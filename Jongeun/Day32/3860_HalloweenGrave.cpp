#include <iostream>
#include <vector>

using namespace std;
#define INF 1e9

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int W, H;
    int G;
    int X, Y;
    int E;
    int X1, Y1, X2, Y2, T;
    while (true)
    {
        cin >> W >> H;
        if (W == 0 && H == 0)
        {
            break;
        }

        int N = W * H;

        vector<int> kinds(N);
        vector<vector<pair<int, int>>> adl(N);

        cin >> G;
        for (int i = 0; i < G; i++)
        {
            cin >> X >> Y;
            int grave = Y * W + X;
            kinds[grave] = 1;
        }

        cin >> E;
        for (int i = 0; i < E; i++)
        {
            cin >> X1 >> Y1 >> X2 >> Y2 >> T;
            int hole = Y1 * W + X1;
            kinds[hole] = 2;
            int exit = Y2 * W + X2;
            adl[hole].push_back({exit, T});
        }

        // construct Adacency List
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    int cur = i * W + j;
                    int nextX = i + dx[k];
                    int nextY = j + dy[k];
                    if (nextX >= 0 && nextX < H && nextY >= 0 && nextY < W)
                    {
                        int next = nextX * W + nextY;
                        if (kinds[cur] != 2 && kinds[next] != 1 && cur != N - 1)
                        {
                            adl[cur].push_back({next, 1});
                        }
                    }
                }
            }
        }

        // Start bellmanford
        vector<long long> dist(N, INF);
        bool cycle = false;
        dist[0] = 0;
        for (int i = 0; i < N; i++)
        {
            // check all the edges
            for (int j = 0; j < N; j++)
            {
                for (int l = 0; l < adl[j].size(); l++)
                {
                    int next = adl[j][l].first;
                    int weight = adl[j][l].second;
                    if ((dist[j] != INF) && (dist[next] > dist[j] + weight))
                    {
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
            cout << "Never" << '\n';
        }
        else if (dist[N - 1] == INF)
        {
            cout << "Impossible" << '\n';
        }
        else
        {
            cout << dist[N - 1] << '\n';
        }
    }

    return 0;
}
