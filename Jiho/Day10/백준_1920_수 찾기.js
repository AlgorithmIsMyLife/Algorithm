const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim()
  .split("\n");

const judgeExistence = (N, nums, M, targets) => {
  // #1. 오름차순 정렬
  nums.sort((a, b) => a - b);
  for (const target of targets) {
    // #2. Index 초기화
    let [left, right] = [0, N - 1];
    let exists = false;
    while (left <= right) {
      const mid = Math.floor((left + right) / 2);
      // #3. 경우의 수 처리
      if (nums[mid] < target) {
        left = mid + 1;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else {
        exists = true;
        break;
      }
    }
    if (exists) {
      console.log(1);
    } else {
      console.log(0);
    }
  }
};

const [N, nums, M, targets] = input;

judgeExistence(
  parseInt(N),
  nums.split(" ").map(Number),
  parseInt(M),
  targets.split(" ").map(Number)
);
