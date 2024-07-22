const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim()
  .split("\n");
const N = input.shift();
const arr = input.map((item) => item.split("").map(Number));

const visitedCoords = {}; // 지금까지 방문한 좌표
const answer = [];
for (let i = 0; i < N; i++) {
  for (let j = 0; j < N; j++) {
    if (arr[i][j] === 1 && !visitedCoords[[i, j]]) answer.push(bfs(i, j));
  }
}

// [x,y] 부터 이어지는 번호의 개수를 구하기
function bfs(x, y) {
  const queue = [[x, y]];
  const visited = {};
  visited[[x, y]] = true;
  visitedCoords[[x, y]] = true;
  let drow = [0, 0, 1, -1];
  let dcol = [-1, 1, 0, 0];
  let cnt = 1;

  while (queue.length) {
    for (let i = 0; i < queue.length; i++) {
      let [row, col] = queue.shift();
      for (let j = 0; j < 4; j++) {
        let nrow = row + drow[j];
        let ncol = col + dcol[j];
        if (
          // 좌표의 유효성 확인
          nrow >= 0 &&
          ncol >= 0 &&
          nrow < arr.length &&
          ncol < arr.length &&
          // 1일 경우에만 진행되므로 1인 경우만 좌표 출력
          arr[nrow][ncol] === 1 &&
          // visited 확인
          !visited[[nrow, ncol]]
        ) {
          visited[[nrow, ncol]] = true;
          visitedCoords[[nrow, ncol]] = true;
          cnt++;
          queue.push([nrow, ncol]);
        }
      }
    }
  }
  return cnt;
}

console.log(answer.length);
answer.sort((a, b) => a - b);
answer.forEach((item) => console.log(item));
