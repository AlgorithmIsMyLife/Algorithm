var permute = function (nums) {
  const len = nums.length;
  const check = new Array(len).fill(false);
  let answer = [];
  const backtracking = (row, accumulate) => {
    // End of DFS
    if (row === len) {
      answer.push([...accumulate]);
      return;
    }
    for (let i = 0; i < len; i++) {
      if (!check[i]) {
        check[i] = true;
        accumulate.push(nums[i]);
        backtracking(row + 1, accumulate);
        check[i] = false;
        accumulate.pop();
      }
    }
  };

  backtracking(0, []);
  return answer;
};

console.log(permute([1, 2, 3, 4]));
