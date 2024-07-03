const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n");

const [N, ...arr] = input;
function solution(N, arr) {
  const emp_set = new Set();
  for (const rec of arr) {
    const [name, command] = rec.trim().split(" ");
    // #1. enter인 경우
    if (command === "enter") {
      emp_set.add(name);
    }
    // #2. leave인 경우
    else if (command === "leave") {
      if (emp_set.has(name)) {
        emp_set.delete(name);
      }
    }
  }
  const emp_arr = [...emp_set];
  // const sorted_arr = emp_arr.sort().reverse();
  const sorted_arr = emp_arr.sort((a, b) => a.localeCompare(b));
  for (const name of sorted_arr) {
    console.log(name);
  }
}

solution(parseInt(N), arr);
