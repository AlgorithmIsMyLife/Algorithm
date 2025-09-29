// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// vector<vector<int>> forest;
// vector<vector<int>> visited; // for jinn to explore

// int R, C, K;
// int dx[] = {-1, 0, 1, 0};
// int dy[] = {0, 1, 0, -1};

// class Result
// {
// public:
//     int row{0};
//     int col{0};
//     int direct{0};
// };

// void BFS(int row, int col, int &maxR)
// {

//     std::queue<pair<int, int>> q;
//     q.push({row, col});

//     while (!q.empty())
//     {
//         int curR = q.front().first;
//         int curC = q.front().second;
//         q.pop();

//         maxR = std::max(maxR, curR - 2);
//         int cur = forest[curR][curC];

//         visited[curR][curC] = -1001; // visited

//         for (int i = 0; i < 4; i++)
//         {
//             if ((curR + dx[i]) < 3 || (curR + dx[i]) > (R + 2) || (curC + dy[i]) < 1 || (curC + dy[i]) > C || forest[curR + dx[i]][curC + dy[i]] == 0)
//             {
//                 continue;
//             }

//             int next = forest[curR + dx[i]][curC + dy[i]];

//             if (visited[curR + dx[i]][curC + dy[i]] == -1001)
//             {
//                 // revisited
//                 continue;
//             }

//             if (next != cur)
//             {
//                 if (cur >= 0 && next != -cur)
//                 {
//                     continue;
//                 }
//             }

//             q.push({curR + dx[i], curC + dy[i]});
//         }
//     }
// }

// Result golemMove(int row, int col, int direction)
// {
//     if (row + 2 > R + 2) // can't go down anymore
//     {
//         return {row, col, direction};
//     }

//     // first south check
//     if (forest[row + 2][col] == 0 && forest[row + 1][col - 1] == 0 && forest[row + 1][col + 1] == 0)
//     {
//         return {row + 1, col, direction};
//     }

//     // second west check
//     if (col - 2 >= 1)
//     {

//         if (forest[row][col - 2] == 0 && forest[row - 1][col - 1] == 0 && forest[row + 1][col - 1] == 0 && forest[row + 2][col - 1] == 0 && forest[row + 1][col - 2] == 0)
//         {
//             return {row + 1, col - 1, (direction - 1 == -1) ? 3 : direction - 1};
//         }
//     }

//     // third east check
//     if (col + 2 <= C)
//     {
//         if (forest[row][col + 2] == 0 && forest[row - 1][col + 1] == 0 && forest[row + 1][col + 1] == 0 && forest[row + 2][col + 1] == 0 && forest[row + 1][col + 2] == 0)
//         {
//             return {row + 1, col + 1, (direction + 1 == 4) ? 0 : direction + 1};
//         }
//     }

//     return {row, col, direction};
// }

// int main()
// {
//     cin >> R >> C >> K;

//     forest.resize(R + 3, vector<int>(C + 1, 0));
//     visited.resize(R + 3, vector<int>(C + 1, 0));

//     int ci, di;
//     int sum = 0;
//     for (int i = 1; i < K + 1; i++)
//     {
//         cin >> ci >> di;

//         int r = 1;
//         int c = ci;

//         while (true)
//         {
//             Result temp = golemMove(r, c, di);
//             if (temp.row == r && temp.col == c)
//             {
//                 break;
//             }
//             else
//             {
//                 r = temp.row;
//                 c = temp.col;
//                 di = temp.direct;
//             }
//         }

//         // edge case check
//         if (r < 4)
//         {
//             // golem body out of forest
//             //  reset the forest
//             for (auto &row : forest)
//             {
//                 std::fill(row.begin(), row.end(), 0);
//             }
//             continue;
//         }
//         else
//         {
//             // mark the golem boundary
//             forest[r][c] = i;
//             for (int j = 0; j < 4; j++)
//             {
//                 if (j == di)
//                 {
//                     forest[r + dx[j]][c + dy[j]] = -i;
//                 }
//                 else
//                 {
//                     forest[r + dx[j]][c + dy[j]] = i;
//                 }
//             }

//             // jinn start to move
//             // do the DFS
//             int res = r - 2;
//             BFS(r, c, res);
//             // reset the visited array
//             for (auto &row : visited)
//             {
//                 std::fill(row.begin(), row.end(), 0);
//             }
//             sum += res;
//         }
//     }

//     cout << sum << '\n';

//     return 0;
// }
