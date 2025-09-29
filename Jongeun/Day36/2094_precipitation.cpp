#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef pair<int, int> ii;

vector<int> st;
vector<ii> arr;
int N;

void init(int node, int start, int end)
{
    if (start == end)
    {
        st[node] = arr[start].second;
        return;
    }

    init(node * 2, start, (start + end) / 2);
    init(node * 2 + 1, (start + end) / 2 + 1, end);
    st[node] = max(st[node * 2], st[node * 2 + 1]);
}

int search(int node, int start, int end, int l, int r)
{
    if (end < l || r < start)
    {
        return 0;
    }

    if (l <= start && end <= r)
    {
        return st[node];
    }

    int lv = search(node * 2, start, (start + end) / 2, l, r);
    int rv = search(node * 2 + 1, (start + end) / 2 + 1, end, l, r);
    return max(lv, rv);
}

int lowerBound(int year) // return lowerbound index
{
    int lb = -1;
    int ub = N, m;
    while (lb + 1 < ub)
    {
        m = (lb + ub) / 2;
        if (arr[m].first < year)
        {
            lb = m;
        }
        else
        {
            ub = m;
        }
    }

    return ub;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    arr.resize(N);
    int y, r;
    unordered_map<int, int> um;
    for (int i = 0; i < N; i++)
    {
        cin >> y >> r;
        arr[i] = {y, r};
        um[y] = i;
    }

    st.resize(N * 4);
    init(1, 0, N - 1);

    int m;
    cin >> m;
    int Y, X;
    for (int i = 0; i < m; i++)
    {
        cin >> Y >> X;
        int upperZ = lowerBound(X) - 1;
        int lowZ = lowerBound(Y + 1);
        int zrain = search(1, 0, N - 1, lowZ, upperZ);

        bool xExist = (um.find(X) != um.end());
        bool yExist = (um.find(Y) != um.end());

        // TODO renewal

        if (xExist && yExist && zrain < arr[um[X]].second && arr[um[X]].second > arr[um[Y]].second)
        {
            cout << "false" << '\n';
        }
        else if (yExist && zrain >= arr[um[Y]].second)
        {
            cout << "false" << '\n';
        }
        else if (xExist && zrain >= arr[um[X]].second)
        {
            cout << "false" << '\n';
        }
        else if (xExist && yExist && (X - Y) == (um[X] - um[Y]))
        {
            cout << "true" << '\n';
        }
        else
        {
            cout << "maybe" << '\n';
        }
    }

    return 0;
}
