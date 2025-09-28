#include <iostream>
#include <vector>

using namespace std;

#define N 1e6

vector<int> st;

void build(int node, int start, int end)
{
    if (start == end)
    {
        st[node] = 0;
        return;
    }

    build(node * 2, start, (start + end) / 2);
    build(node * 2 + 1, (start + end) / 2 + 1, end);
    st[node] = st[node * 2] + st[node * 2 + 1];
}

void update(int node, int start, int end, int order, int val)
{
    if (order < start || end < order)
    {
        return;
    }

    if (start == end)
    {
        st[node] += val;
        return;
    }

    update(node * 2, start, (start + end) / 2, order, val);
    update(node * 2 + 1, (start + end) / 2 + 1, end, order, val);
    st[node] = st[node * 2] + st[node * 2 + 1];
}

int search(int node, int start, int end, int order)
{
    if (start == end)
    {
        return start; // return index which is a taste of candy
    }

    // have childs
    if (order <= st[node * 2])
    {
        return search(node * 2, start, (start + end) / 2, order);
    }
    else
    {
        return search(node * 2 + 1, (start + end) / 2 + 1, end, order - st[node * 2]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    st.resize(N * 4);
    build(1, 1, N);

    int M;
    cin >> M;
    int A, B, C;
    for (int i = 0; i < M; i++)
    {
        cin >> A;
        if (A == 1)
        {
            cin >> B;
            int taste = search(1, 1, N, B);
            cout << taste << '\n';
            update(1, 1, N, taste, -1);
        }
        else
        {
            cin >> B >> C;
            update(1, 1, N, B, C);
        }
    }

    return 0;
}
