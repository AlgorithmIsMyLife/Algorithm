#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> forest;
vector<vector<int>> visited; // for jinn to explore

int R, C, K;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

class Result
{
public:
    int row{0};
    int col{0};
    int direct{0};
};

void DFS(int row, int col, int &maxR)
{

    maxR = std::max(maxR, row);
    int cur = forest[row][col];

    visited[row][col] = -1001; // visited

    for (int i = 0; i < 4; i++)
    {
        if ((row + dx[i]) < 1 || (row + dx[i]) > R || (col + dy[i]) < 1 || (col + dy[i]) > C || forest[row + dx[i]][col + dy[i]] == 0)
        {
            continue;
        }

        int next = forest[row + dx[i]][col + dy[i]];

        if (visited[row + dx[i]][col + dy[i]] == -1001)
        {
            // revisited
            continue;
        }

        if (next != cur)
        {
            if (cur >= 0 && next != -cur)
            {
                continue;
            }
        }

        if (i == 2)
        { // down
            DFS(row + dx[i], col + dy[i], maxR);
        }
        else
        {
            // left or right
            DFS(row + dx[i], col + dy[i], maxR);
        }
    }
}

Result golemMove(int row, int col, int direction)
{
    if (row + 2 > R) // can't go down anymore
    {
        return {row, col, direction};
    }

    // first south check
    if (forest[row + 2][col] == 0 && forest[row + 1][col - 1] == 0 && forest[row + 1][col + 1] == 0)
    {
        return {row + 1, col, direction};
    }

    // second west check
    if (col - 2 >= 1)
    {
        bool examined = true;

        if (row > 0 && (forest[row][col - 2] != 0 || forest[row - 1][col - 1] != 0))
        { // only check when row >0
            examined = false;
        }

        if (forest[row + 1][col - 1] == 0 && forest[row + 2][col - 1] == 0 && forest[row + 1][col - 2] == 0 && examined)
        {
            return {row + 1, col - 1, (direction - 1 == -1) ? 3 : direction - 1};
        }
    }

    // third east check
    if (col + 2 <= C)
    {
        bool examined = true;
        if (row > 0 && (forest[row][col + 2] != 0 || forest[row - 1][col + 1] != 0))
        {
            examined = false;
        }

        if (forest[row + 1][col + 1] == 0 && forest[row + 2][col + 1] == 0 && forest[row + 1][col + 2] == 0 && examined)
        {
            return {row + 1, col + 1, (direction + 1 == 4) ? 0 : direction + 1};
        }
    }

    return {row, col, direction};
}

int main()
{
    cin >> R >> C >> K;

    forest.resize(R + 1, vector<int>(C + 1, 0));
    visited.resize(R + 1, vector<int>(C + 1, 0));

    int ci, di;
    int sum = 0;
    for (int i = 1; i < K + 1; i++)
    {
        cin >> ci >> di;

        int r = -1;
        int c = ci;

        while (true)
        {
            Result temp = golemMove(r, c, di);
            if (temp.row == r && temp.col == c)
            {
                break;
            }
            else
            {
                r = temp.row;
                c = temp.col;
                di = temp.direct;
            }
        }

        // edge case check
        if (r < 2)
        {
            // golem body out of forest
            //  reset the forest
            for (auto &row : forest)
            {
                std::fill(row.begin(), row.end(), 0);
            }
            continue;
        }
        else
        {
            // mark the golem boundary
            forest[r][c] = i;
            for (int j = 0; j < 4; j++)
            {
                if (j == di)
                {
                    forest[r + dx[j]][c + dy[j]] = -i;
                }
                else
                {
                    forest[r + dx[j]][c + dy[j]] = i;
                }
            }

            // jinn start to move
            // do the DFS
            int res = r;
            DFS(r, c, res);
            // reset the visited array
            for (auto &row : visited)
            {
                std::fill(row.begin(), row.end(), 0);
            }
            sum += res;
        }
    }

    cout << sum << '\n';

    return 0;
}
