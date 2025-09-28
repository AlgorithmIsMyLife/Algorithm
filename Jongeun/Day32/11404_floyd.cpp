#include <iostream>
#include <vector>

using namespace std;

#define INF 1e9
vector<vector<int>> adm;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    adm.resize(n + 1, vector<int>(n + 1, INF));

    int a, b, c;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;

        if (adm[a][b] > c)
        {
            adm[a][b] = c;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        adm[i][i] = 0;
    }

    // floyd warshall

    for (int k = 1; k < n + 1; k++)
    {
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (adm[i][j] > (adm[i][k] + adm[k][j]))
                {
                    adm[i][j] = adm[i][k] + adm[k][j];
                }
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (adm[i][j] == INF)
            {
                cout << 0 << ' ';
            }
            else
            {
                cout << adm[i][j] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
