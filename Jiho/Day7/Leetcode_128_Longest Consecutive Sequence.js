const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim()
  .split(" ")
  .map(Number);

var longestConsecutive = function (nums) {
  const arr = [...new Set(nums)].sort((a, b) => a - b);
  const cnt = new Array(arr.length).fill(1);

  if (arr.length === 0) return 0;
  let max = cnt[0]; // 1로 초기화
  for (let i = 1; i < arr.length; i++) {
    if (arr[i] === arr[i - 1] + 1) {
      cnt[i] = cnt[i - 1] + 1;
      if (cnt[i] > max) {
        max = cnt[i];
      }
    }
  }
  return max;
};

console.log(longestConsecutive(input));
