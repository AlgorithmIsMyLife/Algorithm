#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int dp[1001][1001] = {
    0,
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream inputFile("input.txt");
    string tempA, tempB;

    if (inputFile.is_open())
    {
        inputFile >> tempA >> tempB;
    }
    else
    {
        cout << "error" << '\n';
    }

    string A = " " + tempA;
    string B = " " + tempB;

    for (int i = 1; i < A.size(); i++)
    {
        for (int j = 1; j < B.size(); j++)
        {
            if (A[i] == B[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    int r = A.size() - 1;
    int c = B.size() - 1;
    string result = "";
    while (dp[r][c])
    {
        if (dp[r][c] == dp[r][c - 1])
        {
            c = c - 1;
        }
        else if (dp[r][c] == dp[r - 1][c])
        {
            r = r - 1;
        }
        else
        {
            result += B[c];
            r = r - 1;
            c = c - 1;
        }
    }

    reverse(result.begin(), result.end());

    cout << result.size() << '\n';
    if (result.size())
    {
        cout << result << '\n';
    }

    return 0;
}
