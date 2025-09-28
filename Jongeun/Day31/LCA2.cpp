#include <iostream>
#include <vector>
#include <queue>

#define K 17
using namespace std;

vector<vector<int>> adl;
vector<int> visited;
vector<vector<int>> parent;
vector<int> depth;

int lca(int a, int b)
{
    // set the depth equal
    if (depth[a] - depth[b] < 0)
    {
        swap(a, b);
    }

    int diff = depth[a] - depth[b];

    for (int i = 0; diff != 0; i++)
    {
        if (diff % 2 == 1)
        {
            a = parent[i][a];
        }
        diff >>= 1;
    }

    if (a == b)
    {
        return a;
    }

    int k = 16;
    while (k >= 0)
    {
        if (parent[k][a] != parent[k][b])
        {
            a = parent[k][a];
            b = parent[k][b];
        }
        k--;
    }

    return parent[0][a];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N;
    adl.resize(N + 1);

    int a, b;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        adl[a].push_back(b);
        adl[b].push_back(a);
    }

    parent.resize(K, vector<int>(N + 1));
    visited.resize(N + 1, false);
    depth.resize(N + 1, 0);

    // bfs for depth and parent
    queue<int> q;
    q.push(1);
    parent[0][1] = 0;
    int Depth = 0;
    while (!q.empty())
    {
        int cnt = q.size();
        for (int i = 0; i < cnt; i++)
        {
            int v = q.front();
            q.pop();
            visited[v] = true;
            depth[v] = Depth;
            for (int j = 0; j < adl[v].size(); j++)
            {
                if (!visited[adl[v][j]])
                {
                    q.push(adl[v][j]);
                    parent[0][adl[v][j]] = v;
                }
            }
        }
        Depth++;
    }

    // fill the dp parent table
    for (int i = 1; i < K; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            if (j == 1)
            {
                parent[i][j] = 0;
            }
            else
            {
                parent[i][j] = parent[i - 1][parent[i - 1][j]];
            }
        }
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }

    return 0;
}
