const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim()
  .split("\n");

const [N, M] = input.shift().split(" ").map(Number);
const arr = input.map((subarr) => subarr.trim().split(""));
// # 방향 변수
const dr = [0, 1, 0, -1];
const dc = [1, 0, -1, 0];

const queue = [[0, 0, 1]];
let visited = Array.from(new Array(N), () => new Array(M).fill(false));
visited[0][0] = true;
let min = -1;

while (queue.length) {
  const [row, col, cnt] = queue.shift();
  console.log(row, col, cnt);
  // # 도착 지점 도달
  if (row === N - 1 && col === M - 1) {
    min = min === -1 ? cnt : Math.min(min, cnt);
  }
  // # 도착 지점 이동중
  else {
    let i = 0;
    for (i; i < 4; i++) {
      const [nrow, ncol] = [row + dr[i], col + dc[i]];
      if (
        nrow >= 0 &&
        nrow < N &&
        ncol >= 0 &&
        ncol < M &&
        arr[nrow][ncol] === "1"
      ) {
        queue.push([nrow, ncol, cnt + 1]);
        visited[nrow][ncol] = true;
      }
    }
  }
}
console.log(min);

/* 
✍️교훈
처음에는 visited[row][col] = true를 queue에서 꺼냈을 때 했었는데,
Time out Error가 발생함

최적화 필요!!
이때, visited의 뜻 : 해당 점에서 시작하는 모든 경우의 수를 고려했음.
그러면, queue에서 뺐을때 넣는게 아니라, 큐에 넣을때 visited를 바꾸면 최적화 가능
문제는 다음과 같은 상황

1111   [3][3]의 1은 위에서 오는 경로랑 아래로 쭉 돌아서 오는 경로 2가지가 존재. 
1001   이렇게, 모든 경우의 수를 판단해서 최소의 값을 구해야 하는게 아닌가? 라는 생각이 들었음
1001   But, BFS의 개념을 이해하면 된다.
1011   BFS는 같은 LEVEL (거리)를 먼저 판단한다.
1110   같은 점에 서로 다른 시점에 들어왔다는 것은 이미 그 점으로의 최소 길이 아님.
       즉, 먼저 오는 방향이 제일 짧은 길이일 것임 (방향은 다를 수 있지만, 같은 LEVEL에 도달하는 방향이면 어차피 정답은 같다)

추가
만약에, 모든 경로를 구해야하는 거라면 visited = true는 queue에서 꺼냇을 때 하는게 맞다.


따라서, 최적의 상황은 qeuue에 넣을때 하는것.
*/
