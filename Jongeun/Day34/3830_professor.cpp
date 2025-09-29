#include <iostream>
#include <vector>

using namespace std;

vector<long long> val;
vector<int> parent;
vector<int> Rank;

int Find(int v)
{
    if (v == parent[v])
    {
        return v;
    }

    int p = Find(parent[v]);
    val[v] += val[parent[v]];

    return parent[v] = p;
}

void Union(int a, int b, int weight)
{
    // b is weight kg heavior than a
    int aRoot = Find(a);
    int bRoot = Find(b);

    if (aRoot == bRoot)
    {
        return;
    }

    // rank of a is always bigger than rank of b
    if (Rank[bRoot] > Rank[aRoot])
    {
        Union(b, a, -weight);
        return;
    }

    // b will be merged to root of a
    Rank[aRoot] += Rank[bRoot];
    parent[bRoot] = parent[aRoot];
    long long diff = val[a] - val[b] + weight;
    val[bRoot] = val[aRoot] + diff;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true)
    {
        int N, M;
        cin >> N >> M;
        if (N == 0 && M == 0)
        {
            return 0;
        }

        parent.resize(N + 1);
        for (int i = 1; i < N + 1; i++)
        {
            parent[i] = i;
        }

        val.assign(N + 1, 0);
        Rank.assign(N + 1, 1);

        char q;
        int a, b, w;

        for (int i = 0; i < M; i++)
        {
            cin >> q;
            if (q == '!')
            {
                cin >> a >> b >> w;
                Union(a, b, w);
            }
            else
            {
                // q == ?
                cin >> a >> b;
                int l = Find(a);
                int r = Find(b);

                if (l == r)
                {
                    cout << val[b] - val[a] << '\n';
                }
                else
                {
                    cout << "UNKNOWN" << '\n';
                }
            }
        }
    }

    return 0;
}
