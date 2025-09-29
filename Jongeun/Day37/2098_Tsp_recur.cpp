#include <iostream>
#include <vector>
#include <cmath>

#define INF 1e9
using namespace std;

vector<vector<int>> W;
vector<vector<int>> memo;
int N;

int TSP(int v, int last)
{
    int minV = INF;

    if (v == ((1 << N) - 1))
    {
        return W[last][0];
    }

    if (memo[v][last] != -1)
    {
        return memo[v][last];
    }

    for (int i = 0; i < N; i++)
    {
        if ((v & (1 << i)) == 0 && W[last][i] != INF)
        {
            minV = min(minV, TSP(v | (1 << i), i) + W[last][i]);
        }
    }
    memo[v][last] = minV;
    return minV;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    W.resize(N, vector<int>(N));
    memo.resize(1 << N, vector<int>(N, -1));
    int num;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> num;
            if (num == 0)
            {
                num = INF;
            }
            W[i][j] = num;
        }
    }

    cout << TSP(1, 0) << '\n';
}
