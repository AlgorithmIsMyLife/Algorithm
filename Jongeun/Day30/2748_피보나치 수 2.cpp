#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num;
    cin >> num;

    long long first = 0;
    long long second = 1;

    if (num == 1)
    {
        cout << second << '\n';

        return 0;
    }

    for (int i = 1; i < num; i++)
    {
        long long temp = first;
        first = second;
        second = temp + second;
    }

    cout << second << '\n';

    return 0;
}
