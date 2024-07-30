class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, pair<int, int>>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({0, {i, j}});
                }
            }
        }

        int totalTime = 0;
        while (!q.empty())
        {
            auto cell = q.front();
            q.pop();

            int i = cell.second.first;
            int j = cell.second.second;
            int time = cell.first;

            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || grid[i][j] == 3)
            {
                totalTime = max(totalTime, time - 1);
                continue;
            }

            grid[i][j] = 3; // mark it as already visited

            q.push({time + 1, {i + 1, j}});
            q.push({time + 1, {i - 1, j}});
            q.push({time + 1, {i, j + 1}});
            q.push({time + 1, {i, j - 1}});
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return totalTime;
    }
};
