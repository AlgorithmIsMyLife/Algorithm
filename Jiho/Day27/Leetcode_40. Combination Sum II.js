var combinationSum2 = function (candidates, target) {
  const len = candidates.length;
  const totalSum = getSum(candidates);
  let answer = [];
  const DFS = (index, arr, sum, leftOver) => {
    if (sum === target) {
      // 같은거 포함 여부 확인
      const targetMap = getMap(arr);
      let sameExist = false;
      answer.forEach((ans) => {
        if (isIdentical(getMap(ans), targetMap)) {
          sameExist = true;
        }
      });
      !sameExist ? answer.push(arr) : undefined;
      return;
    } else if (index >= len || sum > target || sum + leftOver < target) {
      return;
    }
    // 포함X
    DFS(index + 1, [...arr], sum, leftOver - candidates[index]);
    // 포함O
    arr.push(candidates[index]);
    DFS(
      index + 1,
      [...arr],
      sum + candidates[index],
      leftOver - candidates[index]
    );
  };

  DFS(0, [], 0, totalSum);
  return answer;
};

function isIdentical(iMap, tMap) {
  if (iMap.size !== tMap.size) {
    return false;
  }
  for (let [key, value] of iMap) {
    if (tMap.has(key)) {
      if (value !== tMap.get(key)) {
        return false;
      }
    } else {
      return false;
    }
  }

  return true;
}

function getMap(array) {
  const map = new Map();
  for (const elm of array) {
    map.set(elm, (map.get(elm) | 0) + 1);
  }
  return map;
}
function getSum(array) {
  let sum = 0;
  for (let i = 0; i < array.length; i++) sum += array[i];
  return sum;
}

var combinationSumAns = function (candidates, target) {
  candidates.sort((a, b) => a - b);
  const res = [];

  function dfs(target, start, comb) {
    if (target < 0) {
      return;
    }

    if (target === 0) {
      res.push(comb.slice());
      return;
    }

    for (let i = start; i < candidates.length; i++) {
      if (i > start && candidates[i] === candidates[i - 1]) {
        continue;
      }

      if (candidates[i] > target) {
        break;
      }

      dfs(target - candidates[i], i + 1, comb.concat(candidates[i]));
    }
  }

  dfs(target, 0, []);
  return res;
};

console.log(
  combinationSumAns(
    [
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    ],
    30
  )
);
// console.log(combinationSum2([10, 1, 2, 7, 6, 1, 5], 8));
// console.log(combinationSum2([2, 5, 2, 1, 2], 5));
