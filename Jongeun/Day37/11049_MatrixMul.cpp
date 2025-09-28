#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> DP(N + 1, vector<int>(N + 1));
    vector<int> row(N + 1);
    vector<int> col(N + 1);

    int r, c;
    for (int i = 1; i < N + 1; i++)
    {
        cin >> r >> c;
        row[i] = r;
        col[i] = c;
    }

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; i + j - 1 < N + 1; j++)
        {
            for (int k = j; k < i + j - 1; k++)
            {
                if (k == j)
                {
                    DP[j][j + i - 1] = DP[j][k] + DP[k + 1][i + j - 1] + row[j] * col[k] * col[i + j - 1];
                }
                else
                {
                    DP[j][j + i - 1] = min(DP[j][j + i - 1], DP[j][k] + DP[k + 1][i + j - 1] + row[j] * col[k] * col[i + j - 1]);
                }
            }
        }
    }

    cout << DP[1][N] << '\n';

    return 0;
}
