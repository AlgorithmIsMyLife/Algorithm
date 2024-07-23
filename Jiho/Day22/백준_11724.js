const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim()
  .split("\n");

const [N, M] = input.shift().split(" ").map(Number);
let graph = [...Array(N + 1)].map(() => []);
const visited = new Array(N + 1).fill(false);
const arr = input.map((v) => v.split(" ").map(Number));
// # 입력 처리

// 양방향(무방향) 그래프로 만들기
arr.forEach(([from, to]) => {
  graph[from].push(to);
  graph[to].push(from);
});

const BFS_FindConnected = (node) => {
  const queue = [node];
  visited[node] = true;
  while (queue.length) {
    const val = queue.shift();
    for (const n of graph[val]) {
      if (!visited[n]) {
        visited[n] = true;
        queue.push(n);
      }
    }
  }
};

let answer = 0;
for (i = 1; i <= N; i++) {
  if (!visited[i]) {
    answer++;
    BFS_FindConnected(i);
  }
}
console.log(answer);
