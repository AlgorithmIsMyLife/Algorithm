var fs = require("fs");
var input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim();
var N = parseInt(input);
var arr = new Array(N + 1);
arr[0] = BigInt(0);
arr[1] = BigInt(1);
for (var i = 2; i <= N; i++) {
  arr[i] = arr[i - 1] + arr[i - 2];
}
console.log(arr[N].toString());
