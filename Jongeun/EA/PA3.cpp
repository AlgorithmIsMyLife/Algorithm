#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int solution(string num, int k)
{
    int N = num.size();
    const unsigned long long INF = ULLONG_MAX / 2;
    const int L = 18;
    const int M = 1e9 + 7;

    // Corrected size of num_val to [N][N + 1]
    vector<vector<unsigned long long>> num_val(N, vector<unsigned long long>(N + 1, 0));

    // Precompute num_val[l][r] for substrings of length up to L
    for (int l = 0; l < N; ++l)
    {
        unsigned long long val = 0;
        for (int r = l + 1; r <= N && r - l <= L; ++r)
        {
            val = val * 10 + (num[r - 1] - '0');
            num_val[l][r] = val;
            if (val > INF)
                break; // Avoid overflow
        }
    }

    // Corrected size of dp to [N + 1][k + 2]
    vector<vector<unsigned long long>> dp(N + 1, vector<unsigned long long>(k + 2, INF));
    dp[0][0] = 0;

    // Dynamic Programming to compute the minimal sum
    // dp[i][j] = optimal sum until i end index substrings when that substring diveded in j segments
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= k + 1; ++j) // segment 1 ~  until K+1
        {
            for (int len = 1; len <= min(L, i); ++len)
            {
                int l = i - len; // start index of substring
                if (dp[l][j - 1] == INF)
                    continue;
                unsigned long long val = num_val[l][i];
                if (val > INF)
                    break;
                dp[i][j] = min(dp[i][j], dp[l][j - 1] + val);
            }
        }
    }

    // Find the minimal sum among all possible splits
    unsigned long long answer = INF;
    for (int j = 1; j <= k + 1; ++j)
    {
        if (dp[N][j] < answer)
        {
            answer = dp[N][j];
        }
    }

    return answer % M;
}

int main()
{
    solution("12345", 2);
    return 0;
}
