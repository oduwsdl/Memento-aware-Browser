// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import {Acorn} from './Acorn.js';
import {ECMA_VERSION} from './AcornTokenizer.js';
import {ESTreeWalker} from './ESTreeWalker.js';

export const RelaxedJSONParser = {
  /**
 * @param {string} content
 * @return {*}
 */
  parse(content) {
    content = '(' + content + ')';

    let root;
    try {
      root = Acorn.parse(content, {ecmaVersion: ECMA_VERSION});
    } catch (e) {
      return null;
    }

    const walker = new ESTreeWalker(beforeVisit, afterVisit);

    const rootTip = [];

    /** @type {!Array.<!Context>} */
    const stack = [];

    /** @type {!Context} */
    let stackData = {key: 0, tip: rootTip, state: States.ExpectValue, parentIsArray: true};

    walker.setWalkNulls(true);
    let hasExpression = false;

    walker.walk(root);

    if (hasExpression) {
      return null;
    }
    return rootTip.length ? rootTip[0] : null;

    /**
   * @param {!Context} newStack
   */
    function pushStack(newStack) {
      stack.push(stackData);
      stackData = newStack;
    }

    function popStack() {
      stackData = stack.pop();
    }

    /**
   * @param {*} value
   */
    function applyValue(value) {
      stackData.tip[stackData.key] = value;
      if (stackData.parentIsArray) {
        stackData.key++;
      } else {
        stackData.state = null;
      }
    }

    /**
   * @param {!ESTree.Node} node
   * @return {!Object|undefined}
   */
    function beforeVisit(node) {
      switch (node.type) {
        case 'ObjectExpression': {
          const newTip = {};
          applyValue(newTip);

          pushStack(/** @type {!Context} */ ({key: null, tip: newTip, state: null, parentIsArray: false}));
          break;
        }
        case 'ArrayExpression': {
          const newTip = [];
          applyValue(newTip);

          pushStack({key: 0, tip: newTip, state: States.ExpectValue, parentIsArray: true});
          break;
        }
        case 'Property':
          stackData.state = States.ExpectKey;
          break;
        case 'Literal':
          if (stackData.state === States.ExpectKey) {
            stackData.key = node.value;
            stackData.state = States.ExpectValue;
          } else if (stackData.state === States.ExpectValue) {
            applyValue(extractValue(node));
            return ESTreeWalker.SkipSubtree;
          }
          break;
        case 'Identifier':
          if (stackData.state === States.ExpectKey) {
            stackData.key = /** @type {string} */ (node.name);
            stackData.state = States.ExpectValue;
          } else if (stackData.state === States.ExpectValue) {
            applyValue(extractValue(node));
            return ESTreeWalker.SkipSubtree;
          }
          break;
        case 'UnaryExpression':
          if (stackData.state === States.ExpectValue) {
            applyValue(extractValue(node));
            return ESTreeWalker.SkipSubtree;
          }
          break;
        case 'Program':
        case 'ExpressionStatement':
          break;
        default:
          if (stackData.state === States.ExpectValue) {
            applyValue(extractValue(node));
          }
          return ESTreeWalker.SkipSubtree;
      }
    }

    /**
   * @param {!ESTree.Node} node
   */
    function afterVisit(node) {
      if (node.type === 'ObjectExpression' || node.type === 'ArrayExpression') {
        popStack();
      }
    }

    /**
   * @param {!ESTree.Node} node
   * @return {*}
   */
    function extractValue(node) {
      let isNegative = false;
      const originalNode = node;
      let value;
      if (node.type === 'UnaryExpression' && (node.operator === '-' || node.operator === '+')) {
        if (node.operator === '-') {
          isNegative = true;
        }
        node = /** @type {!ESTree.Node} */ (node.argument);
      }

      if (node.type === 'Literal') {
        value = node.value;
      } else if (node.type === 'Identifier' && Keywords.hasOwnProperty(node.name)) {
        value = Keywords[node.name];
      } else {
        hasExpression = true;
        return content.substring(originalNode.start, originalNode.end);
      }

      if (isNegative) {
        if (typeof value !== 'number') {
          hasExpression = true;
          return content.substring(originalNode.start, originalNode.end);
        }
        value = -(value);
      }
      return value;
    }
  }
};

/** @enum {string} */
export const States = {
  ExpectKey: 'ExpectKey',
  ExpectValue: 'ExpectValue'
};

/** @enum {*} */
export const Keywords = {
  'NaN': NaN,
  'true': true,
  'false': false,
  'Infinity': Infinity,
  'undefined': undefined,
  'null': null
};

/**
 * @typedef {!{key: (number|string), tip: (!Array|!Object), state: ?States, parentIsArray: boolean}}
 */
export let Context;
