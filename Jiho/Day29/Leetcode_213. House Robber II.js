var rob2 = function (nums) {
  const getMax = (nums) => {
    let prevRob = 0,
      maxRob = 0;

    for (let num of nums) {
      let temp = Math.max(maxRob, prevRob + num);
      prevRob = maxRob;
      maxRob = temp;
    }

    return maxRob;
  };

  if (nums.length === 1) return nums[0];
  return Math.max(getMax(nums.slice(0, -1)), getMax(nums.slice(1)), nums[0]);
};

console.log(rob2([1, 2, 3, 1]));
