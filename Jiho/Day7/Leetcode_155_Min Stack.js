var MinStack = function () {
  this.stack = [];
  this.minstack = [];
};

/**
 * @param {number} val
 * @return {void}
 */
MinStack.prototype.push = function (val) {
  let len = this.stack.length;
  this.stack[len] = val;
  if (this.minstack.length === 0 || this.minstack.at(-1) >= val) {
    this.minstack[this.minstack.length] = val;
  }
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function () {
  if (!this.stack.length === 0) {
    return null;
  }
  if (this.minstack.at(-1) === this.stack.at(-1)) {
    this.minstack.length--;
  }
  this.stack.length--;
};

/**
 * @return {number}
 */
MinStack.prototype.top = function () {
  if (this.stack.length === 0) {
    return null;
  }
  return this.stack.at(-1);
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function () {
  if (this.minstack.length === 0) {
    return null;
  }
  return this.minstack.at(-1);
};
