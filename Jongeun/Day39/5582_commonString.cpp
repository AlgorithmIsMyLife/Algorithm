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

    int r = A.size();
    int c = B.size();

    vector<vector<int>> maxlen(r, vector<int>(c, 0));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (A[i] == B[j])
            {

                if (i > 0 && j > 0 && A[i - 1] == B[j - 1]) // string keeps continuing ..
                {
                    maxlen[i][j] = maxlen[i - 1][j - 1] + 1;
                }
                else // restart
                {
                    maxlen[i][j] = 1;
                }

                maxLength = max(maxLength, maxlen[i][j]);
            }
        }
    }

    cout << maxLength << '\n';

    return 0;
}
