#include <iostream>
#include <vector>

#define INF 1000000007

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    vector<int> input(N);
    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;

        if (num > min(i, N - 1 - i))
        {
            cout << 0 << '\n';
            return 0;
        }
        input[i] = num;
    }

    vector<vector<int>> dp(2, vector<int>(5002, 0));

    // Initialize both dp arrays
    dp[0][0] = 1;
    dp[1][0] = 1;

    for (int k = 0; k < N; k++)
    {
        int end = min(k, N - 1 - k);
        int reducedK = k % 2;
        int kBefore = 1 - reducedK;

        // Reset dp[reducedK] before using it
        dp[reducedK].assign(5002, 0);

        if (input[k] == -1)
        {
            for (int j = 0; j <= end; j++)
            {
                int low = (j - 1 >= 0) ? dp[kBefore][j - 1] : 0;
                int mid = dp[kBefore][j];
                int high = dp[kBefore][j + 1];

                dp[reducedK][j] = ((long long)low + mid + high) % INF;
            }
        }
        else
        {
            int level = input[k];
            if (level > end)
            {
                // Invalid level, skip processing
                continue;
            }
            int low = (level - 1 >= 0) ? dp[kBefore][level - 1] : 0;
            int mid = dp[kBefore][level];
            int high = dp[kBefore][level + 1];

            dp[reducedK][level] = ((long long)low + mid + high) % INF;
        }
    }

    cout << dp[(N - 1) % 2][0] << '\n';

    return 0;
}
