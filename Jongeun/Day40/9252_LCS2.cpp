#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string A, B;
    cin >> A >> B;

    int maxLength = 0;
    int maxI = 0;
    int maxJ = 0;

    vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
    vector<vector<pair<int, int>>> beforeIdx(A.size() + 1, vector<pair<int, int>>(B.size() + 1));

    for (int i = 1; i < A.size() + 1; i++)
    {

        int tempX = 0; // initializa idx as (0,0) whoose length is 0
        int tempY = 0;

        for (int j = 1; j < B.size() + 1; j++)
        {
            int X = beforeIdx[i - 1][j].first;
            int Y = beforeIdx[i - 1][j].second;

            if (A[i - 1] == B[j - 1]) // if the letter is the same
            {
                dp[i][j] = dp[X][Y] + 1;

                if (dp[i][j] > maxLength)
                {
                    maxLength = dp[i][j];
                    maxI = i;
                    maxJ = j;
                }

                if (dp[tempX][tempY] > dp[X][Y])
                {
                    beforeIdx[i][j].first = tempX;
                    beforeIdx[i][j].second = tempY;
                }
                else
                {
                    beforeIdx[i][j].first = X;
                    beforeIdx[i][j].second = Y;
                }

                if (dp[i][j] > dp[tempX][tempY])
                {
                    tempX = i;
                    tempY = j;
                }
            }
            else // if the letter is different
            {
                if (dp[tempX][tempY] > dp[X][Y])
                {
                    beforeIdx[i][j].first = tempX;
                    beforeIdx[i][j].second = tempY;
                }
                else
                {
                    beforeIdx[i][j].first = X;
                    beforeIdx[i][j].second = Y;
                }
            }
        }
    }

    cout << maxLength << '\n';
    string st = "";
    if (maxLength > 0)
    {
        int ti = maxI, tj = maxJ;
        while (true)
        {
            st += B[tj - 1];
            ti = beforeIdx[ti][tj].first;
            tj = beforeIdx[ti][tj].second;

            if (dp[ti][tj] == 1)
            {
                break;
            }
        }

        st += B[tj - 1];
    }

    for (int i = st.size() - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            cout << st[i] << '\n';
        }
        else
        {
            cout << st[i];
        }
    }

    return 0;
}
