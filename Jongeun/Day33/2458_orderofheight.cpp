#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> adl;
vector<vector<int>> backAdl;

void dfs(int start, vector<vector<int>> &adl, vector<bool> &visited, int &total)
{
    if (visited[start])
    {
        return;
    }

    visited[start] = true;
    total++;

    for (int i = 0; i < adl[start].size(); i++)
    {
        if (!visited[adl[start][i]])
        {
            dfs(adl[start][i], adl, visited, total);
        }
    }
}

bool isUnique(int start, int N)
{
    vector<bool> visited(N + 1, false);
    int n = 0, m = 0;
    dfs(start, adl, visited, n);
    visited.assign(N + 1, false);
    dfs(start, backAdl, visited, m);

    if (n + m == N + 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    adl.resize(N + 1);
    backAdl.resize(N + 1);

    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        adl[a].push_back(b);
        backAdl[b].push_back(a);
    }

    int total = 0;

    for (int i = 1; i < N + 1; i++)
    {
        if (isUnique(i, N))
        {
            total++;
        }
    }

    cout << total << '\n';
    return 0;
}
