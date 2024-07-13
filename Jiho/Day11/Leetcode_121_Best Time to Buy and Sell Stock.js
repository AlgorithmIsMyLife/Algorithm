// Two Pointer
var maxProfit = function (prices) {
  const len = prices.length;
  if (len === 1) return 0;
  // 길이 2 이상
  let [left, right] = [0, 1]; // index value
  let ans = 0;
  while (left < right && right < len) {
    // #1.
    if (prices[left] >= prices[right]) {
      left = right;
      right = left + 1;
    } else if (prices[left] < prices[right]) {
      // #2. 갱신
      const diff = prices[right] - prices[left];
      ans = ans < diff ? diff : ans;
      right += 1;
    }
  }
  return ans;
};

console.log(maxProfit([7, 6, 4, 3, 1]));
