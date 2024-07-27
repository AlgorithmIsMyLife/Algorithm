var subsetsWithDup = function (nums) {
  const len = nums.length;

  let answer = [];
  const backtracking = (index, accumulate) => {
    if (index === len) {
      // #3. 존재 여부 확인
      const targetMap = getMap(accumulate);
      let sameExist = false;
      answer.forEach((ans) => {
        if (isIdentical(getMap(ans), targetMap)) {
          sameExist = true;
        }
      });
      sameExist === false ? answer.push([...accumulate]) : undefined;

      return;
    }
    // #1. 선택X
    const arr1 = [...accumulate];
    // #2. 선택O
    accumulate.push(nums[index]);
    const arr2 = [...accumulate];

    backtracking(index + 1, arr1);
    backtracking(index + 1, arr2);
  };
  backtracking(0, []);
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
console.log(subsetsWithDup([0]));
