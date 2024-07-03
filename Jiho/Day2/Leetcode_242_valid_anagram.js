const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n");

const [s, t] = input;
var isAnagram = function (s, t) {
  // #1. 저장 배열
  const arr = new Array(26).fill(0);
  const charstr = s.split("");

  for (const char of charstr) {
    const idx = char.charCodeAt() - 97;
    arr[idx] += 1;
  }
  const inputstr = t.split("");
  for (const char of inputstr) {
    const idx = char.charCodeAt() - 97;
    if (arr[idx] > 0) {
      arr[idx] -= 1;
    } else {
      return false;
    }
  }
  // #2. 남아있는거 있음?
  let i = 0;
  for (i; i < 26; i++) {
    if (arr[i] != 0) return false;
  }
  return true;
};

console.log(isAnagram(s.trim(), t));
