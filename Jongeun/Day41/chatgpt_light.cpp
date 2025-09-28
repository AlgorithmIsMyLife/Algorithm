#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    // Compress the sequence by removing consecutive duplicates
    vector<int> colors;
    colors.push_back(arr[0]);
    for (int i = 1; i < N; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            colors.push_back(arr[i]);
        }
    }

    int L = colors.size();
    vector<vector<int>> dp(L, vector<int>(L, 0));

    // Build the DP table
    for (int length = 2; length <= L; length++)
    {
        for (int i = 0; i <= L - length; i++)
        {
            int j = i + length - 1;
            if (colors[i] == colors[j])
            {
                dp[i][j] = dp[i + 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
            }
        }
    }

    cout << dp[0][L - 1] << '\n';

    return 0;
}
