const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim()
  .split("\n");

var twoSum = function (numbers, target) {
  let left = 0,
    right = numbers.length - 1;
  while (left < right) {
    const sum = numbers[left] + numbers[right];
    // #1. 큰 경우
    if (sum > target) {
      right -= 1;
    }
    // #2. 작은 경우
    else if (sum < target) {
      left += 1;
    }
    // #3. 정답
    else {
      return [left + 1, right + 1];
    }
  }
};

const [inputs, t] = input;
console.log(twoSum(inputs.split(" ").map(Number), parseInt(t)));
