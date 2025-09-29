var search = function (nums, target) {
  const arr = nums.toSorted((a, b) => a - b);
  // console.log(arr);
  let [left, right] = [0, arr.length - 1];
  while (left <= right) {
    // console.log("left: ", left, "right: ", right);
    const mid = Math.floor((left + right) / 2);
    if (arr[mid] < target) {
      left = mid + 1;
    } else if (arr[mid] > target) {
      right = mid - 1;
    } else {
      // console.log("Found mid: ", mid);
      return nums.indexOf(target);
    }
  }
  return -1;
};

// Without sorting
var without_search = function (nums, target) {
  const len = nums.length;
  let [left, right] = [0, len - 1];

  while (left <= right) {
    const mid = Math.floor((left + right) / 2);
    // console.log("left:", left, "right:", right, "mid:", mid);
    if (nums[mid] === target) {
      return mid;
    } else if (nums[left] <= nums[mid]) {
      if (nums[left] <= target && target <= nums[mid]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    } else {
      if (nums[mid] <= target && target <= nums[right]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }
  return -1;
};
console.log(without_search([3, 1], 1));
