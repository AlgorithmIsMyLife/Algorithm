#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
typedef pair<int, int> pii;

vector<int> dp;
vector<int> arr;
vector<int> idx;
vector<pii> arr2; // arr that preserve the LIS . {element, idx}

bool comp(const pii &a, const pii &b)
{
    return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    arr.resize(N + 1);
    dp.resize(N + 1);
    idx.resize(N + 1);

    int temp;
    for (int i = 1; i < N + 1; i++)
    {
        cin >> temp;
        arr[i] = temp;
    }

    // push the first element in advance
    dp[1] = 1;
    idx[1] = -1;
    arr2.push_back({arr[1], 1});

    for (int i = 2; i < N + 1; i++)
    {
        auto lowIdx = lower_bound(arr2.begin(), arr2.end(), make_pair(arr[i], i), comp) - arr2.begin();
        if (lowIdx == arr2.size())
        {
            arr2.push_back({arr[i], i});
            int before = arr2[lowIdx - 1].second;
            dp[i] = dp[before] + 1;
            idx[i] = before;
        }
        else
        {
            arr2[lowIdx] = {arr[i], i};
            if (lowIdx == 0)
            {
                idx[i] = -1;
                dp[i] = 1;
            }
            else
            {
                int before = arr2[lowIdx - 1].second;
                dp[i] = dp[before] + 1;
                idx[i] = before;
            }
        }
    }

    cout << arr2.size() << '\n';

    stack<int> stk;
    int num = arr2[arr2.size() - 1].second;
    while (num != -1)
    {
        stk.push(arr[num]);
        num = idx[num];
    }

    while (!stk.empty())
    {
        cout << stk.top() << ' ';
        stk.pop();
    }

    return 0;
}
