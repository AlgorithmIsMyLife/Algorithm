#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    // Grid to store waste paper information
    vector<vector<int>> A(N + 1, vector<int>(M + 1, 0));

    // Reading the grid input
    for (int i = 1; i <= N; ++i)
    {
        string line;
        cin >> line;
        for (int j = 1; j <= M; ++j)
        {
            if (line[j - 1] == '*')
            {
                A[i][j] = 1; // Waste paper
            }
            else if (line[j - 1] == '#')
            {
                A[i][j] = -1; // Blocked cell
            }
        }
    }

    // Initialize a 4D DP table with dimensions for two paths
    vector<vector<vector<vector<int>>>> D(N + 1, vector<vector<vector<int>>>(M + 1, vector<vector<int>>(N + 1, vector<int>(M + 1, -1))));

    // Base case: both paths start at (1, 1)
    D[1][1][1][1] = A[1][1]; // If there's waste paper at (1, 1), we start with it

    // Process all possible states
    for (int i1 = 1; i1 <= N; ++i1)
    {
        for (int j1 = 1; j1 <= M; ++j1)
        {
            for (int i2 = 1; i2 <= N; ++i2)
            {
                for (int j2 = 1; j2 <= M; ++j2)
                {
                    // Skip invalid positions or blocked cells
                    if (A[i1][j1] == -1 || A[i2][j2] == -1)
                        continue;
                    // you can assume the column of A is always left or equal to the column of B
                    if (j1 > j2)
                        continue;

                    // Maximize from four previous states
                    int value = -1;
                    if (i1 > 1 && i2 > 1)
                        value = max(value, D[i1 - 1][j1][i2 - 1][j2]);
                    if (i1 > 1 && j2 > 1)
                        value = max(value, D[i1 - 1][j1][i2][j2 - 1]);
                    if (j1 > 1 && i2 > 1)
                        value = max(value, D[i1][j1 - 1][i2 - 1][j2]);
                    if (j1 > 1 && j2 > 1)
                        value = max(value, D[i1][j1 - 1][i2][j2 - 1]);

                    if (value == -1)
                        continue; // If no valid previous state, skip

                    D[i1][j1][i2][j2] = value + A[i1][j1]; // Add waste paper at i1,j1

                    // If the two paths are on different cells, add waste paper from the second path
                    if (i1 != i2 || j1 != j2)
                    {
                        D[i1][j1][i2][j2] += A[i2][j2];
                    }
                }
            }
        }
    }

    // The final result will be the maximum waste collected when both paths finish at (N, M)
    cout << D[N][M][N][M] << endl;

    return 0;
}
