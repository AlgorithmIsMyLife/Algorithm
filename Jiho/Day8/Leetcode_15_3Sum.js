const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim()
  .split(" ")
  .map(Number);

function find_bigger_mismatch(nums, start_index) {
  const len = nums.length;

  let left_add = 1;
  while (
    start_index + left_add < len &&
    nums[start_index + left_add] === nums[start_index]
  ) {
    left_add += 1;
  }
  return left_add;
}
function find_smaller_mismatch(nums, start_index) {
  const len = nums.length;

  let right_minus = 1;
  while (
    start_index - right_minus >= 0 &&
    nums[start_index - right_minus] === nums[start_index]
  ) {
    right_minus += 1;
  }

  return right_minus;
}

var threeSum = function (nums) {
  nums.sort((a, b) => a - b);
  const len = nums.length;
  const ans = [];
  for (let a = 0; a < len; ) {
    const target = -1 * nums[a];
    let left = a + 1;
    let right = len - 1;
    while (left < right) {
      const sum = nums[left] + nums[right];
      if (sum == target) {
        ans.push([nums[a], nums[left], nums[right]]);
        // 같은 만큼 더하기
        left += find_bigger_mismatch(nums, left);
        // 같은 만큼 뺴기
        right -= find_smaller_mismatch(nums, right);
      } else if (sum > target) {
        right -= find_smaller_mismatch(nums, right);
      } else if (sum < target) {
        left += find_bigger_mismatch(nums, left);
      }
    }
    a += find_bigger_mismatch(nums, a);
  }
  return ans;
};

console.log(threeSum(input));
