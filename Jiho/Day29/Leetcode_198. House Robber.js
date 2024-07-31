var rob = function (nums) {
  const len = nums.length;

  let arr = new Array(len);
  arr[0] = nums[0];
  arr[1] = Math.max(nums[0], nums[1]);
  let i;
  for (i = 2; i < len; i++) {
    arr[i] = Math.max(arr[i - 1], arr[i - 2] + nums[i]);
  }

  return arr[len - 1];
};

console.log(rob([2, 1]));

// DP
