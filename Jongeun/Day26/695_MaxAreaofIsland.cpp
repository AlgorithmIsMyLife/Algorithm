class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int total = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int tempMax{0};
                    dfs(grid, tempMax, i, j, m, n);
                    if (tempMax >= total)
                    {
                        total = tempMax;
                    }
                }
            }
        }

        return total;
    }

    void dfs(vector<vector<int>> &grid, int &tempMax, int i, int j, int m, int n)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1 || grid[i][j] == 0)
        {
            return;
        }

        grid[i][j] = -1;
        tempMax++;

        dfs(grid, tempMax, i - 1, j, m, n);
        dfs(grid, tempMax, i + 1, j, m, n);
        dfs(grid, tempMax, i, j - 1, m, n);
        dfs(grid, tempMax, i, j + 1, m, n);
    }
};
