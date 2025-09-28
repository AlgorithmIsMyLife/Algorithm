#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> times;
vector<int> maxTimes;
vector<vector<int>> adl;
vector<int> indegree;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    times.resize(N + 1);
    maxTimes.resize(N + 1);
    indegree.resize(N + 1);
    adl.resize(N + 1);

    int t, a;
    for (int i = 1; i < N + 1; i++)
    {
        cin >> t;
        times[i] = t;
        maxTimes[i] = t;

        cin >> a;
        while (a != -1)
        {
            adl[a].push_back(i);
            indegree[i]++;
            cin >> a;
        }
    }

    queue<int> Q;

    for (int i = 1; i < N + 1; i++)
    {
        if (indegree[i] == 0)
        {
            Q.push(i);
        }
    }

    while (!Q.empty())
    {
        int v = Q.front();
        Q.pop();

        for (int i = 0; i < adl[v].size(); i++)
        {
            int next = adl[v][i];

            if (maxTimes[v] + times[next] > maxTimes[next])
            {
                maxTimes[next] = maxTimes[v] + times[next];
            }

            indegree[next]--;
            if (indegree[next] == 0)
            {
                Q.push(next);
            }
        }
    }

    for (int i = 1; i < N + 1; i++)
    {
        cout << maxTimes[i] << '\n';
    }

    return 0;
}
