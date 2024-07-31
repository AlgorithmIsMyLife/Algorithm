#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int S;
    cin >> S;

    int temp;
    vector<int> permutation;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        permutation.push_back(temp);
    }

    int l = 0, r = 0;
    int sum = 0;
    int minLength = INT_MAX;

    while (r < permutation.size())
    {
        sum += permutation[r];

        if (sum < S)
        {
            r++;
        }
        else
        {
            while (l <= r && sum >= S)
            {
                minLength = min(minLength, r - l + 1);
                sum -= permutation[l];
                l++;
            }
            r++;
        }
    }

    if (minLength == INT_MAX)
    {
        cout << 0 << '\n';
    }
    else
    {
        cout << minLength << '\n';
    }

    return 0;
}
