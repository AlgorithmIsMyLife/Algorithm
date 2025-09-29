#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> arr(N + 1);
    int num;
    for (int i = 1; i <= N; i++)
    {
        cin >> num;
        arr[i] = num;
    }

    vector<int> cost(N + 1);
    int total = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> num;
        cost[i] = num;
        total += num;
    }

    vector<vector<int>> dp(N + 1, vector<int>(total + 1));

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 0; j < total + 1; j++)
        {
            int payment = cost[i];
            int memory = arr[i];

            if (i == 1)
            {
                if (j - payment >= 0)
                {
                    dp[i][j] = memory;
                }
            }
            else
            {
                if (j - payment >= 0 && (dp[i - 1][j - payment] + memory) > dp[i - 1][j])
                {
                    dp[i][j] = dp[i - 1][j - payment] + memory;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }

            if (i == N && dp[i][j] >= M)
            {
                cout << j << '\n';
                break;
            }
        }
    }

    return 0;
}
