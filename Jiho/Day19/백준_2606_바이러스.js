const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim()
  .split("\n");

const [N, M, ...connectionsArr] = input;
const numOfDesktop = parseInt(N);
const numOfConnections = parseInt(M);
const connections = connectionsArr.map((elm) =>
  elm.trim().split(" ").map(Number)
);
const graph = Array.from(Array(numOfDesktop + 1), () => new Array());

for (const [l, r] of connections) {
  graph[l].push(r);
  graph[r].push(l);
}

// Using Stack dfs
let answer = 0;

const stack = [1];
const visited = new Array(numOfDesktop + 1).fill(false);
visited[1] = true;
while (stack.length) {
  const target = stack.pop();
  answer += 1;
  // push values connected to val while not visited
  for (const val of graph[target]) {
    if (!visited[val]) {
      stack.push(val);
      visited[val] = true;
    }
  }
}
console.log(answer - 1);
