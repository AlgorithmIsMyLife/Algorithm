var searchRange = function (nums, target) {
  let arr = [];
  let [left, right] = [0, nums.length - 1];
  const find_match = (l, r) => {
    while (l <= r) {
      const mid = Math.floor((l + r) / 2);
      const val = nums[mid];
      if (val > target) {
        r = mid - 1;
      } else if (val < target) {
        l = mid + 1;
      } else {
        arr.push(mid);
        find_match(l, mid - 1);
        find_match(mid + 1, r);
        return;
      }
    }
  };

  find_match(left, right);

  return arr.length === 0 ? [-1, -1] : [Math.min(...arr), Math.max(...arr)];
};

console.log(searchRange([], 6));
