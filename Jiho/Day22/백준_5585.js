const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim();

let money = 1000 - parseInt(input);

let answer = 0;
const costs = [500, 100, 50, 10, 5, 1];
for (const cost of costs) {
  const cnt = Math.floor(money / cost);
  answer += cnt;
  money -= cost * cnt;
}

console.log(answer);
