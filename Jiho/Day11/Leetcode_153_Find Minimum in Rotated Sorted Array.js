var findMin = function (nums) {
  nums.sort((a, b) => a - b);
  return nums[0];
};

console.log(findMin([3, 4, 5, 1, 2]));
