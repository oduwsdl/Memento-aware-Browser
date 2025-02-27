import { extractImportantStackTrace } from '../util/stack.js';

export class LogMessageWithStack extends Error {
  private stackHidden: boolean = false;
  private timesSeen: number = 1;

  constructor(name: string, ex: Error) {
    super(ex.message);

    this.name = name;
    this.stack = ex.stack;
  }

  /** Set a flag so the stack is not printed in toJSON(). */
  setStackHidden() {
    this.stackHidden = true;
  }

  /** Increment the "seen x times" counter. */
  incrementTimesSeen() {
    this.timesSeen++;
  }

  toJSON(): string {
    let m = this.name + ': ';
    if (!this.stackHidden && this.stack) {
      // this.message is already included in this.stack
      m += extractImportantStackTrace(this);
    } else {
      m += this.message;
    }
    if (this.timesSeen > 1) {
      m += `\n(seen ${this.timesSeen} times with identical stack)`;
    }
    return m;
  }
}
