const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim()
  .split("\n");

const [arr, k] = input;

var topKFrequent = function (nums, k) {
  let obj = {};
  for (const num of nums) {
    // #1. 없음
    if (!obj[num]) {
      obj[num] = 1;
    }
    // #2. 있음
    else {
      obj[num] += 1;
    }
  }
  let arr = Object.entries(obj).sort((a, b) => b[1] - a[1]);
  console.log(arr);
  const res = [];
  for (let i = 0; i < k; i++) {
    res.push(parseInt(arr[i][0]));
  }
  return res;
};

// solution
var solution_topKFrequent = function (nums, k) {
  let map = new Map();

  for (let num of nums) {
    // map.get(num) || 0  => 없으면 0 있으면 해당 값
    map.set(num, (map.get(num) || 0) + 1);
  }

  const sortedByValue = [...map.entries()].sort((a, b) => b[1] - a[1]);

  let out = sortedByValue.slice(0, k).map((entry) => entry[0]);

  return out;
};

console.log(topKFrequent(arr.split(" ").map(Number), parseInt(k)));
