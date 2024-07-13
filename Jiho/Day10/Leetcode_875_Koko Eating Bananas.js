var minEatingSpeed = function (piles, h) {
  let [left, right] = [1, Math.max(...piles)];

  let min = -1; // speed

  while (left <= right) {
    // #1. mid spped 값 계산
    const mid = Math.floor((left + right) / 2);
    let numOfHours = 0;
    for (const pile of piles) {
      numOfHours += Math.ceil(pile / mid);
    }
    // #2. 검사
    if (h >= numOfHours) {
      min = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return min;
};

console.log(minEatingSpeed([3, 6, 7, 11], 8));
