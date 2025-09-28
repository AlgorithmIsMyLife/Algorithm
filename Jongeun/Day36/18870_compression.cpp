#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int num;
    vector<ii> arr(N);
    vector<int> originArr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        arr[i] = {num, i};
        originArr[i] = num;
    }

    vector<int> ans(N);

    sort(arr.begin(), arr.end());

    int cnt = 0;
    ans[arr[0].second] = cnt;
    for (int i = 1; i < N; i++)
    {
        if (arr[i - 1].first != arr[i].first)
        {
            cnt++;
        }

        ans[arr[i].second] = cnt;
    }

    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << ' ';
    }

    return 0;
}
