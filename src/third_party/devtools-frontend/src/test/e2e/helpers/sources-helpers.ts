// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import {assert} from 'chai';
import * as puppeteer from 'puppeteer';

import {$, $$, click, getBrowserAndPages, goToResource, step, typeText, waitFor} from '../../shared/helper.js';

export const PAUSE_ON_EXCEPTION_BUTTON = '[aria-label="Pause on exceptions"]';
export const PAUSE_BUTTON = '[aria-label="Pause script execution"]';
export const RESUME_BUTTON = '[aria-label="Resume script execution"]';
export const SOURCES_LINES_SELECTOR = '.CodeMirror-code > div';
export const PAUSE_INDICATOR_SELECTOR = '.paused-status';

export async function doubleClickSourceTreeItem(selector: string) {
  await waitFor(selector);
  await click(selector, {clickOptions: {clickCount: 2}});
}

export async function openSourcesPanel() {
  // Locate the button for switching to the sources tab.
  await click('#tab-sources');

  // Wait for the navigation panel to show up
  await waitFor('.navigator-file-tree-item');
}

export async function openFileInSourcesPanel(testInput: string) {
  await goToResource(`sources/${testInput}`);

  await openSourcesPanel();
}

export async function openSnippetsSubPane() {
  await click('[aria-label="More tabs"]', {root: await $('.navigator-tabbed-pane')});
  await waitFor('[aria-label="Snippets"]');

  await click('[aria-label="Snippets"]');
  await waitFor('[aria-label="New snippet"]');
}

export async function createNewSnippet(snippetName: string) {
  const {frontend} = await getBrowserAndPages();

  await click('[aria-label="New snippet"]');
  await waitFor('[aria-label^="Script%20snippet"]');

  await typeText(snippetName);

  await frontend.keyboard.press('Enter');
}

export async function openFileInEditor(sourceFile: string) {
  // Open a particular file in the editor
  await doubleClickSourceTreeItem(`[aria-label="${sourceFile}, file"]`);

  // Wait for the file to be formattable, this process is async after opening a file
  await waitFor(`[aria-label="Pretty print ${sourceFile}"]`);
}

export async function openSourceCodeEditorForFile(sourceFile: string, testInput: string) {
  await openFileInSourcesPanel(testInput);
  await openFileInEditor(sourceFile);
}

export async function getOpenSources() {
  const sourceTabPane = await waitFor('#sources-panel-sources-view .tabbed-pane');
  const sourceTabs = (await $('.tabbed-pane-header-tabs', sourceTabPane)).asElement()!;
  const openSources =
      await sourceTabs.$$eval('.tabbed-pane-header-tab', nodes => nodes.map(n => n.getAttribute('aria-label')));
  return openSources;
}

// We can't use the click helper, as it is not possible to select a particular
// line number element in CodeMirror.
export async function addBreakpointForLine(frontend: puppeteer.Page, index: number, expectedFail: boolean = false) {
  await frontend.waitForFunction(index => {
    return document.querySelectorAll('.CodeMirror-linenumber').length >= index;
  }, undefined, index);
  const breakpointLineNumber = await frontend.evaluate(index => {
    const element = document.querySelectorAll('.CodeMirror-linenumber')[index];

    const {left, top, width, height} = element.getBoundingClientRect();
    return {
      x: left + width * 0.5,
      y: top + height * 0.5,
    };
  }, index);

  const currentBreakpointCount = await frontend.$$eval('.cm-breakpoint', nodes => nodes.length);

  await frontend.mouse.click(breakpointLineNumber.x, breakpointLineNumber.y);

  if (expectedFail) {
    return;
  }

  await frontend.waitForFunction(bpCount => {
    return document.querySelectorAll('.cm-breakpoint').length > bpCount &&
        document.querySelectorAll('.cm-breakpoint-unbound').length === 0;
  }, undefined, currentBreakpointCount);
}

export async function sourceLineNumberSelector(lineNumber: number) {
  return `div.CodeMirror-code > div:nth-child(${lineNumber}) div.CodeMirror-linenumber.CodeMirror-gutter-elt`;
}

export async function checkBreakpointIsActive(lineNumber: number) {
  await step(`check that the breakpoint is still active at line ${lineNumber}`, async () => {
    const codeLineNums = await (await $$(SOURCES_LINES_SELECTOR)).evaluate(elements => {
      return elements.map((el: HTMLElement) => el.className);
    });
    assert.deepInclude(codeLineNums[lineNumber - 1], 'cm-breakpoint');
    assert.notDeepInclude(codeLineNums[lineNumber - 1], 'cm-breakpoint-disabled');
    assert.notDeepInclude(codeLineNums[lineNumber - 1], 'cm-breakpoint-unbound');
  });
}

export async function checkBreakpointIsNotActive(lineNumber: number) {
  await step(`check that the breakpoint is not active at line ${lineNumber}`, async () => {
    const codeLineNums = await (await $$(SOURCES_LINES_SELECTOR)).evaluate(elements => {
      return elements.map((el: HTMLElement) => el.className);
    });
    assert.notDeepInclude(codeLineNums[lineNumber - 1], 'cm-breakpoint');
  });
}

export async function checkBreakpointDidNotActivate() {
  await step('check that the script did not pause', async () => {
    // TODO(almuthanna): make sure this check happens at a point where the pause indicator appears if it was active
    const breakpointIndicator = await (await $$(PAUSE_INDICATOR_SELECTOR)).evaluate(elements => {
      return elements.map((el: HTMLElement) => el.className);
    });
    assert.deepEqual(breakpointIndicator.length, 0, 'script had been paused');
  });
}

export async function getBreakpointDecorators(frontend: puppeteer.Page, disabledOnly = false) {
  const selector = `.cm-breakpoint${disabledOnly ? '-disabled' : ''} .CodeMirror-linenumber`;
  return await frontend.$$eval(selector, nodes => nodes.map(n => parseInt(n.textContent!, 0)));
}

export async function getNonBreakableLines(frontend: puppeteer.Page) {
  const selector = '.cm-non-breakable-line .CodeMirror-linenumber';
  await waitFor(selector, undefined, 1000);
  return await frontend.$$eval(selector, nodes => nodes.map(n => parseInt(n.textContent!, 0)));
}

export async function getExecutionLine() {
  const activeLine = await waitFor('.cm-execution-line-outline', undefined, 1000);
  return await activeLine.asElement()!.evaluate(n => parseInt(n.textContent!, 10));
}

export async function retrieveTopCallFrameScriptLocation(script: string, target: puppeteer.Page) {
  // The script will run into a breakpoint, which means that it will not actually
  // finish the evaluation, until we continue executing.
  // Thus, we have to await it at a later point, while stepping through the code.
  const scriptEvaluation = target.evaluate(script);

  // Wait for the evaluation to be paused and shown in the UI
  await waitFor(PAUSE_INDICATOR_SELECTOR);

  // Retrieve the top level call frame script location name
  const scriptLocation =
      await (await $('.call-frame-location')).evaluate((location: HTMLElement) => location.textContent);

  // Resume the evaluation
  await click(RESUME_BUTTON);

  // Make sure to await the context evaluate before asserting
  // Otherwise the Puppeteer process might crash on a failure assertion,
  // as its execution context is destroyed
  await scriptEvaluation;

  return scriptLocation;
}

export async function retrieveTopCallFrameWithoutResuming() {
  // Wait for the evaluation to be paused and shown in the UI
  await waitFor(PAUSE_INDICATOR_SELECTOR);

  // Retrieve the top level call frame script location name
  const scriptLocation =
      await (await $('.call-frame-location')).evaluate((location: HTMLElement) => location.textContent);

  return scriptLocation;
}

declare global {
  interface Window {
    __sourceFilesAddedEvents: string[];
  }
}

export function listenForSourceFilesAdded(frontend: puppeteer.Page) {
  return frontend.evaluate(() => {
    window.__sourceFilesAddedEvents = [];
    window.addEventListener('source-tree-file-added', (event: Event) => {
      const customEvent = event as CustomEvent<string>;
      if (customEvent.detail !== '/__puppeteer_evaluation_script__') {
        window.__sourceFilesAddedEvents.push(customEvent.detail);
      }
    });
  });
}

export function waitForAdditionalSourceFiles(frontend: puppeteer.Page, count = 1) {
  return frontend.waitForFunction(count => {
    return window.__sourceFilesAddedEvents.length >= count;
  }, undefined, count);
}

export function clearSourceFilesAdded(frontend: puppeteer.Page) {
  return frontend.evaluate(() => window.__sourceFilesAddedEvents = []);
}

export function retrieveSourceFilesAdded(frontend: puppeteer.Page) {
  // Strip hostname, to make it agnostic of which server port we use
  return frontend.evaluate(() => window.__sourceFilesAddedEvents.map(file => new URL(`http://${file}`).pathname));
}

// Helpers for navigating the file tree.
export type NestedFileSelector = {
  rootSelector: string,
  domainSelector: string,
  folderSelector: string,
  fileSelector: string,
};

export function createSelectorsForWorkerFile(
    workerName: string, folderName: string, fileName: string, workerIndex = 1): NestedFileSelector {
  const rootSelector = new Array(workerIndex).fill(`[aria-label="${workerName}, worker"]`).join(' ~ ');
  const domainSelector = `${rootSelector} + ol > [aria-label="localhost:8090, domain"]`;
  const folderSelector = `${domainSelector} + ol > [aria-label^="${folderName}, "]`;
  const fileSelector = `${folderSelector} + ol > [aria-label="${fileName}, file"]`;

  return {
    rootSelector,
    domainSelector,
    folderSelector,
    fileSelector,
  };
}

async function expandSourceTreeItem(selector: string) {
  const sourceTreeItem = await waitFor(selector, undefined, 1000);
  const isExpanded = await sourceTreeItem.asElement()!.evaluate(element => {
    return element.getAttribute('aria-expanded') === 'true';
  });
  if (!isExpanded) {
    await doubleClickSourceTreeItem(selector);
  }
}

export async function expandFileTree(selectors: NestedFileSelector) {
  await expandSourceTreeItem(selectors.rootSelector);
  await expandSourceTreeItem(selectors.domainSelector);
  await expandSourceTreeItem(selectors.folderSelector);
  return await waitFor(selectors.fileSelector, undefined, 1000);
}

export async function openNestedWorkerFile(selectors: NestedFileSelector) {
  await expandFileTree(selectors);
  await click(selectors.fileSelector);
}

export async function clickOnContextMenu(selector: string, label: string) {
  // Find the selected node, right click.
  const selectedNode = await $(selector);
  await click(selectedNode, {clickOptions: {button: 'right'}});

  // Wait for the context menu option, and click it.
  const labelSelector = `[aria-label="${label}"]`;
  await waitFor(labelSelector);
  await click(labelSelector);
}
