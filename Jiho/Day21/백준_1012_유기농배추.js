const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim()
  .split("\n");
const TESTCASE = parseInt(input.shift());

const BFS_SearchConnected = (startRow, startCol, N, M, visited, vegi) => {
  // # 방향
  const dr = [0, 1, 0, -1];
  const dc = [1, 0, -1, 0];

  const queue = [[startRow, startCol]];
  visited[startRow][startCol] = true;

  while (queue.length) {
    // console.log("Here");
    // console.log(queue.shift());
    const [row, col] = queue.shift();
    for (let i = 0; i < 4; i++) {
      const [nrow, ncol] = [row + dr[i], col + dc[i]];
      if (
        nrow >= 0 &&
        nrow < N &&
        ncol >= 0 &&
        ncol < M &&
        !visited[nrow][ncol] &&
        vegi[nrow][ncol] === 1
      ) {
        visited[nrow][ncol] = true;
        queue.push([nrow, ncol]);
      }
    }
  }
};

// 각각의 TestCase
for (let tc = 0; tc < TESTCASE; tc++) {
  // # 입력 처리
  const [M, N, K] = input.shift()?.split(" ").map(Number);
  const vegi = Array.from(new Array(N), () => new Array(M).fill(0));

  for (let i = 0; i < K; i++) {
    const [inputCol, inputRow] = input.shift()?.trim().split(" ").map(Number);
    vegi[inputRow][inputCol] = 1;
  }
  // # 방문 처리
  const visited = Array.from(new Array(N), () => new Array(M).fill(false));

  let answer = 0;
  for (let row = 0; row < N; row++) {
    for (let col = 0; col < M; col++) {
      if (!visited[row][col] && vegi[row][col] === 1) {
        answer += 1;
        BFS_SearchConnected(row, col, N, M, visited, vegi);
      }
    }
  }
  console.log(answer);
}
