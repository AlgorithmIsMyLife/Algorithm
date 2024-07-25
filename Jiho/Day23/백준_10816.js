const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim()
  .split("\n");

const N = parseInt(input[0]);
const carr = input[1].trim().split(" ").map(Number);
const M = parseInt(input[2]);
const nums = input[3].trim().split(" ").map(Number);

// Map 만들기
let map = new Map();
for (const val of carr) {
  map.set(val, (map.get(val) | 0) + 1);
}

// 결과 만들기
const result = [];
for (const num of nums) {
  result.push(map.get(num) | 0);
}
console.log(result.join(" "));
