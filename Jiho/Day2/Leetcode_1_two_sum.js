const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n");

var twoSum = function (nums, target) {
  const len = nums.length;
  let left = 0;
  let right = len - 1;
  // #1. 정렬
  const arr = nums.toSorted((a, b) => a - b);
  while (left <= right) {
    const sum = arr[left] + arr[right];
    if (sum < target) {
      left += 1;
    } else if (sum > target) {
      right -= 1;
    } else {
      // #2. 위치 찾기
      let result = [];

      nums.forEach((num, index) => {
        if (num === arr[left] || num === arr[right]) {
          result.push(index);
        }
      });

      return result;
    }
  }
};

const [input_arr, N] = input;

console.log(twoSum(input_arr.split(" ").map(Number), parseInt(N)));
