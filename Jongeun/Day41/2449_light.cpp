#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    int num;
    vector<int> arr(N + 1);
    for (int i = 1; i < N + 1; i++)
    {
        cin >> num;
        arr[i] = num;
    }

    vector<vector<int>> dp(N + 1, vector<int>(N + 1));

    for (int i = 1; i <= N; i++) // i means interval
    {
        for (int j = 1; j + i - 1 <= N; j++)
        {
            for (int k = j; k < j + i - 1; k++)
            {
                if (k == j)
                {
                    dp[j][j + i - 1] = dp[j][k] + dp[k + 1][j + i - 1] + ((arr[j] == arr[k + 1]) ? 0 : 1);
                }
                else
                {
                    dp[j][j + i - 1] = min(dp[j][j + i - 1], dp[j][k] + dp[k + 1][j + i - 1] + ((arr[j] == arr[k + 1]) ? 0 : 1));
                }
            }
        }
    }

    cout << dp[1][N] << '\n';

    return 0;
}
