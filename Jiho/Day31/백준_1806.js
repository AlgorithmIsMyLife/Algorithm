const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim()
  .split("\n");

// N: 길이, M: target 크기
const [N, M] = input.shift()?.trim().split(" ").map(Number);
const arr = input.toString().split(" ").map(Number);

let [left, right] = [0, 0];

// #1. 초기 l,r 찾기
let sum = arr[left];
let min = 0;
while (right < N && sum < M) {
  right += 1;
  sum += arr[right];
}
// 답 없음
if (right === N) {
  console.log(min);
}
// 초기 답 있음
else {
  min = right - left + 1;
  // Two Pointer 반복문
  while (true) {
    sum -= arr[left];
    left += 1;
    while (right < N && sum < M) {
      right++;
      sum += arr[right];
    }
    // 넘어감
    if (right === N) {
      break;
    }
    // 찾음
    else {
      min = Math.min(min, right - left + 1);
    }
  }
  console.log(min);
}
