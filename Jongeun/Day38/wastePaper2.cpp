#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int N, M;
    cin >> N >> M;
    vector<vector<int>> grid(M + 1, vector<int>(N + 1, 0));
    vector<vector<vector<int>>> dp(M + N - 1, vector<vector<int>>(M + 1, vector<int>(M + 1, -1)));

    for (int i = 1; i <= M; i++)
    {
        string line;
        cin >> line;
        for (int j = 1; j <= N; j++)
        {
            if (line[j - 1] == '*')
            {
                grid[i][j] = 1;
            }
            else if (line[j - 1] == '#')
            {
                grid[i][j] = -1; // Blocked cell
            }
        }
    }

    dp[0][1][1] = (grid[1][1] == 1) ? 1 : 0;
    // M+N-2 is the number of moves
    for (int i = 1; i <= M + N - 2; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            for (int k = 1; k <= M; k++)
            {

                int y1 = i - j + 2;
                int y2 = i - k + 2;

                if (j > i + 1 || k > i + 1)
                    continue;

                // Ensure positions are valid and within bounds
                if (y1 < 1 || y1 > N || y2 < 1 || y2 > N || grid[j][y1] == -1 || grid[k][y2] == -1)
                {
                    continue; // Skip blocked cells or out-of-bounds positions
                }

                int max_prev = -1;
                if (j > 1 && k > 1)
                    max_prev = max(max_prev, dp[i - 1][j - 1][k - 1]);
                if (j > 1)
                    max_prev = max(max_prev, dp[i - 1][j - 1][k]);
                if (k > 1)
                    max_prev = max(max_prev, dp[i - 1][j][k - 1]);
                max_prev = max(max_prev, dp[i - 1][j][k]);

                if (max_prev == -1)
                    continue;

                dp[i][j][k] = max_prev + grid[j][y1];
                if (j != k)
                {
                    dp[i][j][k] += grid[k][y2];
                }
            }
        }
    }

    cout << dp[M + N - 2][M][M] << endl;

    return 0;
}
