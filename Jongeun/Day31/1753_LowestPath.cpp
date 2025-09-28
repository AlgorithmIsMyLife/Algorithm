#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

vector<vector<pair<int, int>>> adl; //(weight, vertex)
vector<int> dist;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    cin >> V >> E;
    adl.resize(V + 1);

    int start;
    cin >> start;
    int u, v, w;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        adl[u].push_back({w, v});
    }

    priority_queue<pair<int, int>> pq;
    dist.resize(V + 1, INT_MAX);

    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        int vertex = pq.top().second;
        pq.pop();

        for (auto e : adl[vertex])
        {
            int next = e.second;
            int weight = e.first;
            if (dist[vertex] + weight < dist[next])
            {
                dist[next] = dist[vertex] + weight;
                pq.push({-dist[next], next});
            }
        }
    }

    for (int i = 1; i < dist.size(); i++)
    {
        if (dist[i] == INT_MAX)
        {
            cout << "INF" << '\n';
        }
        else
        {
            cout << dist[i] << '\n';
        }
    }

    return 0;
}
