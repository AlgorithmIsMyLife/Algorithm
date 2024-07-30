#include <bits/stdc++.h>
using namespace std;

bool fmin(long long v, long long X, long long Y)
{
    return Y * (100) / X < (Y + v) * 100 / (X + v);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long X;
    long long Y;
    cin >> X;
    cin >> Y;

    if (Y * 100 / X >= 99)
    {
        cout << -1 << '\n';
        return 0;
    }

    long long lb = 0;
    long long ub = 1000000000; // verified 98% -> 99%

    while (lb + 1 < ub)
    {
        long long m = lb + (ub - lb) / 2;
        if (fmin(m, X, Y))
        {
            ub = m;
        }
        else
        {
            lb = m;
        }
    }

    cout << ub << '\n';

    return 0;
}
