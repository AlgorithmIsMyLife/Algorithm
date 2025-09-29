const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim()
  .split("\n");

const [c, arr] = input;
const [N, K] = c.split(" ").map(Number);
const solution = (N, K, nums) => {
  // #1. 초기화
  let sum = 0;
  for (let i = 0; i < K; i++) {
    sum += nums[i];
  }
  let cnt = 1;
  let max = sum;

  let [l, r] = [1, K];
  while (r < N) {
    sum += nums[r] - nums[l - 1];
    if (max < sum) {
      max = sum;
      cnt = 1;
    } else if (max === sum) {
      cnt += 1;
    }
    l++;
    r++;
  }
  if (max === 0) {
    console.log("SAD");
  } else {
    console.log(max);
    console.log(cnt);
  }
};

solution(N, K, arr.split(" ").map(Number));
