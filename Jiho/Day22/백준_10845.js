const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim()
  .split("\n");

const N = Number(input[0]);

let arr = [];
let i;
let answer = [];
for (i = 1; i <= N; i++) {
  let cmd = input[i].trim().split(" ");
  switch (cmd[0]) {
    case "push":
      arr.push(parseInt(cmd[1]));
      break;
    case "pop":
      if (arr.length === 0) answer.push(-1);
      else {
        const val = arr.shift();
        answer.push(val);
      }
      break;
    case "size":
      answer.push(arr.length);
      break;
    case "empty":
      if (arr.length) {
        answer.push(0);
      } else {
        answer.push(1);
      }
      break;
    case "front":
      arr.length === 0 ? answer.push(-1) : answer.push(arr[0]);
      break;
    case "back":
      arr.length === 0 ? answer.push(-1) : answer.push(arr[arr.length - 1]);
      break;
  }
}

console.log(answer.join("\n"));
