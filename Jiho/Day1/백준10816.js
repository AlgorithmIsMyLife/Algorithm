const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n");

const [N, cardstr, M, arrstr] = input;
const cards = cardstr.split(" ").map(Number);
const arr = arrstr.split(" ").map(Number);

function solution(N, cards, M, arr) {
  // #1. 집합 만들기
  const card_set = new Set();
  for (const card of cards) {
    card_set.add(card);
  }
  let res = "";
  for (const num of arr) {
    if (card_set.has(num)) {
      res += "1 ";
    } else {
      res += "0 ";
    }
  }
  return res;
}

console.log(solution(parseInt(N), cards, parseInt(M), arr));
