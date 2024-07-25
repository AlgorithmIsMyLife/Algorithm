const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim()
  .split("\n");

// 저장
let answers = [];
while (true) {
  const [w, h] = input.shift()?.split(" ").map(Number);

  if (w === 0 && h === 0) {
    break;
  }
  let map = Array.from(new Array(h), () => new Array(w));
  let visited = Array.from(new Array(h), () => new Array(w).fill(false));

  for (let i = 0; i < h; i++) {
    const arr = input.shift()?.split(" ").map(Number);
    for (let j = 0; j < w; j++) {
      map[i][j] = arr[j];
    }
  }

  const BFS_FindConnected = (startRow, startCol, map, visited) => {
    const dr = [0, 1, 1, 1, 0, -1, -1, -1];
    const dc = [1, 1, 0, -1, -1, -1, 0, 1];
    visited[startRow][startCol] = true;
    let queue = [[startRow, startCol]];
    while (queue.length) {
      const [row, col] = queue.shift();

      for (let i = 0; i < 8; i++) {
        const [nrow, ncol] = [row + dr[i], col + dc[i]];
        if (
          nrow >= 0 &&
          nrow < h &&
          ncol >= 0 &&
          ncol < w &&
          !visited[nrow][ncol] &&
          map[nrow][ncol] === 1
        ) {
          visited[nrow][ncol] = true;
          queue.push([nrow, ncol]);
        }
      }
    }
  };

  // Execute BFS
  let answer = 0;
  for (let row = 0; row < h; row++) {
    for (let col = 0; col < w; col++) {
      if (!visited[row][col] && map[row][col] === 1) {
        answer++;
        BFS_FindConnected(row, col, map, visited);
      }
    }
  }
  answers.push(answer);
}
console.log(answers.join("\n"));
