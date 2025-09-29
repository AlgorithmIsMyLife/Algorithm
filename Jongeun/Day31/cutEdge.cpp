#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adl;
vector<int> orderList;
vector<int> visited;
vector<pair<int, int>> result;
int order = 0;

int dfs(int v, int parent)
{
    visited[v] = true;
    orderList[v] = order++;

    int returnV = orderList[v];
    for (int i : adl[v])
    {
        if (!visited[i])
        {
            int low = dfs(i, v);
            returnV = min(returnV, low);
            if (low > orderList[v])
            {
                if (i > v)
                {
                    result.push_back({v, i});
                }
                else
                {
                    result.push_back({i, v});
                }
            }
        }
        else if (i != parent)
        {
            returnV = min(returnV, orderList[i]);
        }
    }

    return returnV;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int V, E;

    cin >> V >> E;
    adl.resize(V + 1);
    orderList.resize(V + 1);
    visited.resize(V + 1);

    int a, b;
    for (int i = 0; i < E; i++)
    {
        cin >> a >> b;
        adl[a].push_back(b);
        adl[b].push_back(a);
    }

    dfs(1, -1);
    sort(result.begin(), result.end());

    cout << result.size() << '\n';
    for (auto i : result)
    {
        cout << i.first << ' ' << i.second << '\n';
    }

    return 0;
}
