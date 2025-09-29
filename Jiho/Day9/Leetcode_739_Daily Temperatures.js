// O(n^2) Time out Error (10^4 * 10^4 = 1초)
// 해당 경우 10^5이므로 TOE
var dailyTemperatures1 = function (temperatures) {
  const output = [];
  let stack = [];
  while (temperatures.length > 0) {
    const target = temperatures.pop();
    let cnt = 0;
    let flag = false;
    for (const num of stack) {
      if (num <= target) cnt++;
      else {
        cnt++;
        flag = true;
        break;
      }
    }
    stack.unshift(target);
    if (flag) {
      output.unshift(cnt);
    } else {
      output.unshift(0);
    }
  }
  return output;
};

//
var dailyTemperatures = function (temperatures) {
  const len = temperatures.length;

  const idx_stack = [];
  const output = new Array(len).fill(0);

  for (let i = 0; i < temperatures.length; i++) {
    const target = temperatures[i];
    while (
      idx_stack.length > 0 &&
      target > temperatures[idx_stack[idx_stack.length - 1]]
    ) {
      const idx = idx_stack.pop();
      output[idx] = i - idx;
    }
    idx_stack.push(i);
  }
  return output;
};
console.log(dailyTemperatures([73, 74, 75, 71, 69, 72, 76, 73]));
