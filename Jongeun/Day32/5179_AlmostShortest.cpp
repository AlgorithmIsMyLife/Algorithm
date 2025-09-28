#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

struct node
{
    int weight;
    int cur;
    int pre;

    node(int w, int c, int p) : weight(w), cur(c), pre(p) {}
};

struct compare
{
    bool operator()(const node &a, const node &b)
    {
        return a.weight > b.weight;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    while (true)
    {
        cin >> N >> M;
        if (N == 0 && M == 0)
        {
            return 0;
        }
        vector<vector<pair<int, int>>> adl(N);

        int S, D;
        cin >> S >> D;
        int U, V, P;

        for (int i = 0; i < M; i++)
        {
            cin >> U >> V >> P;
            adl[U].push_back({P, V}); //{weight, vertex}
        }

        priority_queue<node, vector<node>, compare> pq;

        pq.push(node(0, S, -1));
        vector<int> dist(N, INF);
        dist[S] = 0;

        vector<vector<int>> adl2(N);
        vector<int> visited(N, false);

        // first Dijkstra
        while (!pq.empty())
        {

            int cur = pq.top().cur;
            int distance = pq.top().weight;
            int pre = pq.top().pre;
            pq.pop();

            if (distance != dist[cur])
            {
                continue;
            }
            else
            {
                if (pre != -1)
                {
                    adl2[cur].push_back(pre);
                }
            }

            if (visited[cur])
            {
                continue;
            }
            else
            {
                visited[cur] = true;
            }
            // edge relaxation

            for (int i = 0; i < adl[cur].size(); i++)
            {
                int next = adl[cur][i].second;
                int weight = adl[cur][i].first;

                if (dist[cur] + weight <= dist[next])
                {
                    dist[next] = dist[cur] + weight;
                    pq.push(node(dist[next], next, cur));
                }
            }
        }

        // Delete most shortest path using the bfs
        vector<bool> visited2(N, false);
        queue<int> q;
        q.push(D);

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            if (visited2[cur])
            {
                continue;
            }

            visited2[cur] = true;

            for (int i = 0; i < adl2[cur].size(); i++)
            {
                int next = adl2[cur][i];
                q.push(next);

                // delete shortest edge
                for (int j = 0; j < adl[next].size(); j++)
                {
                    int cur2 = adl[next][j].second;
                    if (cur2 == cur)
                    {
                        adl[next][j].first = INF;
                    }
                }
            }
        }

        // again do dijkstra
        dist.assign(N, INF);
        dist[S] = 0;

        priority_queue<pair<int, int>> pq2;
        pq2.push({0, S});

        while (!pq2.empty())
        {
            int cur = pq2.top().second;
            pq2.pop();

            for (int i = 0; i < adl[cur].size(); i++)
            {
                int next = adl[cur][i].second;
                int weight = adl[cur][i].first;
                if (weight != INF && dist[cur] + weight < dist[next])
                {
                    dist[next] = dist[cur] + weight;
                    pq2.push({-dist[next], next});
                }
            }
        }

        if (dist[D] == INF)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << dist[D] << '\n';
        }
    }

    return 0;
}
