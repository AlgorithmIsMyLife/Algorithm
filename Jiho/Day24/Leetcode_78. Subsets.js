var subsets = function (nums) {
  let accumulate = [];
  let answer = [];
  function backtracking(arr, index) {
    // 마지막
    if (index === nums.length) {
      answer.push(arr);
      return;
    }
    const cpy = [...arr];
    backtracking(cpy, index + 1);
    arr.push(nums[index]);
    backtracking(arr, index + 1);
  }
  backtracking(accumulate, 0);

  return answer;
};

console.log(subsets([1, 2, 3]));
