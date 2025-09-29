const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim()
  .split(" ")
  .map(Number);

var productExceptSelf = function (nums) {
  const len = nums.length;

  let prev = Array(len).fill(1);
  let after = Array(len).fill(1);
  let answer = [];

  let i;
  // #1. prev 채우기
  for (i = 1; i < len; i++) {
    prev[i] = prev[i - 1] * nums[i - 1];
  }
  // #2. after 채우기
  for (i = len - 2; i >= 0; i--) {
    after[i] = after[i + 1] * nums[i + 1];
  }
  for (i = 0; i < len; i++) {
    answer.push(prev[i] * after[i]);
  }
  return answer;
};

console.log(productExceptSelf(input));
