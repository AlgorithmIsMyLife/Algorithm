const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim()
  .split("\n");

// 입력 받기
const [height, width] = input.shift()?.split(" ").map(Number);
const arr = Array.from(Array(height), () => new Array(width));

for (let row = 0; row < height; row++) {
  const rowInput = input[row];
  for (let col = 0; col < width; col++) {
    arr[row][col] = rowInput[col];
  }
}

const BFS = (startRow, startCol, visited) => {
  const queue = [[startRow, startCol]];
  while (queue.length) {
    const [row, col] = queue.shift();

    const val = arr[row][col];
    //
    if (val === "-") {
      if (
        col + 1 < width &&
        arr[row][col + 1] === "-" &&
        !visited[row][col + 1]
      ) {
        visited[row][col + 1] = true;
        queue.push([row, col + 1]);
      }
    }
    //
    else if (val === "|") {
      if (
        row + 1 < height &&
        arr[row + 1][col] === "|" &&
        !visited[row + 1][col]
      ) {
        visited[row + 1][col] = true;
        queue.push([row + 1, col]);
      }
    }
  }
};

let answer = 0;
let visited = Array.from(Array(height), () => new Array(width).fill(false));
for (let i = 0; i < height; i++) {
  for (let j = 0; j < width; j++) {
    if (!visited[i][j]) {
      answer++;
      visited[i][j] = true;
      BFS(i, j, visited);
    }
  }
}

console.log(answer);
