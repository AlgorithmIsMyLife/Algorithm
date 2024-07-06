const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim();

/*--------------------------------------------------------------------------------
  #1 1475번
*/
function solution(val) {
  const arr = val.toString().split("");
  const cnt_arr = Array(10).fill(0);
  const cnt_arr69 = Array(2).fill(0);
  let i;
  for (i = 0; i < arr.length; i++) {
    const val = parseInt(arr[i]);
    if (val == 6) {
      cnt_arr69[0] += 1;
    } else if (val == 9) {
      cnt_arr69[1] += 1;
    } else {
      cnt_arr[val] += 1;
    }
  }

  const res = [...cnt_arr, Math.ceil((cnt_arr69[0] + cnt_arr69[1]) / 2)];
  return Math.max(...res);
}

console.log(solution(parseInt(input)));
