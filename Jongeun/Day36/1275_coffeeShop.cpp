#include <iostream>
#include <vector>

using namespace std;

class SegTree
{
public:
    SegTree(vector<int> &ar) : arr(ar), st(arr.size() * 4)
    {
        build(1, 1, arr.size() - 1);
    }

    void build(long long node, int start, int end)
    {
        if (start == end)
        {
            st[node] = arr[start];
            return;
        }

        build(2 * node, start, (start + end) / 2);
        build(2 * node + 1, (start + end) / 2 + 1, end);
        st[node] = st[node * 2] + st[node * 2 + 1];
    }

    long long search(int node, int start, int end, int left, int right)
    {
        if (end < left || right < start)
        {
            return 0;
        }

        if (left <= start && end <= right)
        {
            return st[node];
        }

        long long l = search(2 * node, start, (start + end) / 2, left, right);
        long long r = search(2 * node + 1, (start + end) / 2 + 1, end, left, right);
        return l + r;
    }

    void update(int node, int start, int end, int order, int val)
    {
        if (order < start || end < order)
        {
            return;
        }

        if (start == end)
        {
            st[node] = val;
            return;
        }

        update(2 * node, start, (start + end) / 2, order, val);
        update(2 * node + 1, (start + end) / 2 + 1, end, order, val);
        st[node] = st[node * 2] + st[node * 2 + 1];
    }

private:
    vector<int> arr;
    vector<long long> st;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N + 1);
    int num;
    for (int i = 1; i < N + 1; i++)
    {
        cin >> num;
        arr[i] = num;
    }
    SegTree st(arr);

    int x, y, a, b;
    for (int i = 0; i < Q; i++)
    {
        cin >> x >> y >> a >> b;
        if (x < y)
        {
            cout << st.search(1, 1, N, x, y) << '\n';
        }
        else
        {
            cout << st.search(1, 1, N, y, x) << '\n';
        }
        st.update(1, 1, N, a, b);
    }

    return 0;
}
