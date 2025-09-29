#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define H 17
#define INF 1e9

vector<vector<pair<int, int>>> adl;
vector<vector<int>> DP;
vector<int> depth;
vector<vector<pair<int, int>>> minMax;
vector<int> visited;

void LCA(int a, int b)
{
    pair<int, int> aMinMax = {INF, 0};
    pair<int, int> bMinMax = {INF, 0};

    // adjust the depth to the same level
    int diff = depth[a] - depth[b];
    if (diff < 0)
    { // depth of a is always deeper
        LCA(b, a);
        return;
    }

    for (int i = 0; diff != 0; i++)
    {
        if (diff % 2 == 1)
        {
            aMinMax.first = min(aMinMax.first, minMax[i][a].first);
            aMinMax.second = max(aMinMax.second, minMax[i][a].second);
            a = DP[i][a];
        }
        diff >>= 1;
    }

    if (a == b)
    {
        cout << aMinMax.first << ' ' << aMinMax.second << '\n';
        return;
    }

    // find the LCA
    for (int i = H - 1; i >= 0; i--)
    {
        int aParent = DP[i][a];
        int bParent = DP[i][b];

        if (aParent != bParent)
        {
            aMinMax.first = min(aMinMax.first, minMax[i][a].first);
            aMinMax.second = max(aMinMax.second, minMax[i][a].second);
            bMinMax.first = min(bMinMax.first, minMax[i][b].first);
            bMinMax.second = max(bMinMax.second, minMax[i][b].second);

            a = aParent;
            b = bParent;
        }
    }

    int lca = DP[0][a];
    aMinMax.first = min(aMinMax.first, minMax[0][a].first);
    aMinMax.second = max(aMinMax.second, minMax[0][a].second);
    bMinMax.first = min(bMinMax.first, minMax[0][b].first);
    bMinMax.second = max(bMinMax.second, minMax[0][b].second);
    cout << min(aMinMax.first, bMinMax.first) << ' ' << max(aMinMax.second, bMinMax.second) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    adl.resize(N + 1);
    DP.resize(H, vector<int>(N + 1));
    depth.resize(N + 1);
    minMax.resize(H, vector<pair<int, int>>(N + 1));
    visited.resize(N + 1, false);

    int A, B, C;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> A >> B >> C;
        adl[A].push_back({B, C});
        adl[B].push_back({A, C});
    }

    // BFS for finding depth , parent, and initial min, max

    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        int v = q.front();
        visited[v] = true;
        q.pop();
        for (int i = 0; i < adl[v].size(); i++)
        {
            int next = adl[v][i].first;
            if (!visited[next])
            {
                int weight = adl[v][i].second;
                DP[0][next] = v;
                minMax[0][next] = {weight, weight};
                depth[next] = depth[v] + 1;
                q.push(next);
            }
        }
    }

    // Fill the parent and update minMax;
    for (int i = 1; i < H; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            if (j == 1)
            {
                DP[i][j] = 0;
                minMax[i][j] = {0, 0};
            }
            else
            {
                DP[i][j] = DP[i - 1][DP[i - 1][j]];
                int parent = DP[i - 1][j];
                minMax[i][j].first = min(minMax[i - 1][j].first, minMax[i - 1][parent].first);
                minMax[i][j].second = max(minMax[i - 1][j].second, minMax[i - 1][parent].second);
            }
        }
    }

    int K;
    cin >> K;

    int D, E;
    for (int i = 0; i < K; i++)
    {
        cin >> D >> E;
        LCA(D, E);
    }

    return 0;
}
