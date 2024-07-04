const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim()
  .split(" ")
  .map(Number);

function solution(array) {
  let obj = {};
  for (let i = 0; i < array.length; i++) {
    if (!obj[array[i]]) {
      obj[array[i]] = 1;
    } else {
      obj[array[i]] += 1;
    }
  }

  let answer;
  let isDup = false;
  for (const key in obj) {
    // #1. 최대값 동일
    if (obj[key] === obj[answer]) {
      isDup = true;
    }
    // #2. 최대값 갱신
    else if (!answer || obj[key] > obj[answer]) {
      answer = key;
      isDup = false;
    }
  }
  if (isDup) return -1;
  return parseInt(answer);
}

console.log(solution(input));
