#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

#define INF 1e9

vector<vector<pair<int, int>>> adl; //(vertex,weight)
vector<long long> dist;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    adl.resize(N + 1);
    dist.resize(N + 1, INF);
    int a, b, c;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        adl[a].push_back({b, c});
    }

    // Bellman ford
    dist[1] = 0;
    bool cycle = false;
    for (int i = 0; i < N; i++) // repeat N times for detecting negative cycle
    {
        for (int j = 1; j < N + 1; j++)
        {
            for (auto e : adl[j])
            {
                int next = e.first;
                long long weight = e.second;

                if (dist[j] + weight < dist[next])
                {
                    if (dist[j] == INF)
                        continue;
                    dist[next] = dist[j] + weight;
                    if (i == N - 1)
                    {
                        cycle = true;
                    }
                }
            }
        }
    }

    if (cycle)
    {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 2; i < N + 1; i++)
    {
        if (dist[i] == INF)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << dist[i] << '\n';
        }
    }

    return 0;
}
