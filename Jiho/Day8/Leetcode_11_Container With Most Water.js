const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim()
  .split(" ")
  .map(Number);

var maxArea = function (height) {
  const len = height.length;

  let left = 0;
  let right = len - 1;
  let max = Math.min(height[left], height[right]) * (len - 1); // 초기 최대값
  while (left < right) {
    max =
      max < Math.min(height[left], height[right]) * (right - left)
        ? Math.min(height[left], height[right]) * (right - left)
        : max;

    // #1. left가 min인 경우 -> left 선택
    if (height[left] < height[right]) {
      left++;
    }
    // #2. right가 min인 경우 -> right 선택
    else if (height[left] >= height[right]) {
      right--;
    }
  }
  return max;
};

// Soltuion
var maxArea_solution = function (height) {
  let maxArea = 0;
  let left = 0;
  let right = height.length - 1;

  while (left < right) {
    // 좀더 깔끔한 작성법
    maxArea = Math.max(
      maxArea,
      (right - left) * Math.min(height[left], height[right])
    );

    if (height[left] < height[right]) {
      left++;
    } else {
      right--;
    }
  }

  return maxArea;
};

console.log(maxArea(input));
