var combinationSum = function (candidates, target) {
  const len = candidates.length;
  let answer = [];
  let accumulate = [];
  function backtracking(remain, arr, index) {
    if (remain === 0) {
      answer.push(arr);
      return;
    }
    if (index < 0) {
      return;
    }
    const val = candidates[index];
    const q = Math.floor(remain / val); // q번 만큼 backtracking 해야함

    for (let i = q; i >= 0; i--) {
      const new_arr = [...arr];
      for (let j = 0; j < i; j++) {
        new_arr.push(val);
      }

      backtracking(remain - i * val, new_arr, index - 1);
    }
  }

  backtracking(target, accumulate, len - 1);
  return answer;
};

console.log(combinationSum([2], 1));
