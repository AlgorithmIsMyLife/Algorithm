const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim()
  .split("\n");

const [constants, ...arr] = input;
const [N, M] = constants.split(" ").map(Number);
const prices = arr.map((elm) => elm.trim().split(" ").map(Number));

// #1. 최소가격 구하기
let minSetPrice = Math.min(...prices.map((item) => item[0]));
let minIndPrice = Math.min(...prices.map((item) => item[1]));
// #2. 계산
let price = 0;
// #1. 6개 가격 >= 6 * 낱개 가격
if (minSetPrice >= 6 * minIndPrice) {
  price = minIndPrice * N;
}
// #2. 정상 경우
else {
  price += Math.floor(N / 6) * minSetPrice;
  if (minSetPrice > (N % 6) * minIndPrice) {
    price += (N % 6) * minIndPrice;
  } else {
    price += minSetPrice;
  }
}
console.log(price);
