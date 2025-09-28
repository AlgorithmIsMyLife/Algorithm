#include <iostream>
#include <vector>
#include <cmath>

#define INF 1e9
using namespace std;

vector<vector<int>> W;
int N;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    W.resize(N, vector<int>(N));
    int num;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> num;
            if (num == 0)
            {
                num = INF;
            }
            W[i][j] = num;
        }
    }

    int end = pow(2, N);
    vector<vector<int>> dp(end, vector<int>(N, INF));

    dp[0][0] = 0; // start at 0

    for (int i = 1; i < end; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int val = (1 << j) & i;
            if (val != 0 && i != (end - 1))
            {
                // already visited and i is not the last index
                continue;
            }
            for (int k = 0; k < N; k++)
            {
                int bitmask = i & (1 << k);
                if (bitmask != 0)
                {
                    // visited Kth town before
                    dp[i][j] = min(dp[i][j], dp[i - bitmask][k] + W[k][j]);
                }
            }
        }
    }

    cout << dp[end - 1][0] << '\n';
    return 0;
}
