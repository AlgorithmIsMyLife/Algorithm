const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim()
  .split("\n")
  .map(Number);

function solution(K, nums) {
  let stack = [];
  for (const num of nums) {
    // #1. 정상 숫자
    if (num != 0) {
      stack.push(num);
    }
    // #2. 실수로 부른 경우
    else if (num === 0) {
      stack.pop();
    }
  }
  let sum = 0;
  stack.forEach((elm) => {
    sum += elm;
  });
  return sum;
}
const [K, ...numbers] = input;
console.log(solution(K, numbers));
