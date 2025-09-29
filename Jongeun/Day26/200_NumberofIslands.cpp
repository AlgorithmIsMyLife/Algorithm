class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int total = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '#')
                {
                    // already visited
                    continue;
                }
                else if (grid[i][j] == '1')
                {
                    total++;
                    dfs(grid, i, j, m, n);
                }
            }
        }

        return total;
    }

    void dfs(vector<vector<char>> &grid, int i, int j, int m, int n)
    {
        if (grid[i][j] == '#' || grid[i][j] == '0')
        {
            return;
        }

        grid[i][j] = '#';

        if (i - 1 >= 0)
        {
            dfs(grid, i - 1, j, m, n);
        }

        if (i + 1 < m)
        {
            dfs(grid, i + 1, j, m, n);
        }

        if (j - 1 >= 0)
        {
            dfs(grid, i, j - 1, m, n);
        }

        if (j + 1 < n)
        {
            dfs(grid, i, j + 1, m, n);
        }
    }
};
