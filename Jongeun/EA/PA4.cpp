#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<vector<int>> edges)
{
    int N = edges.size() + 1;           // Total number of nodes
    vector<vector<int>> adj(N + 1);     // Adjacency list (1-based)
    vector<int> degree(N + 1, 0);       // Degree of each node (1-based)
    vector<bool> visited(N + 1, false); // Visited nodes
    vector<int> answer;                 // Result list

    // Build the adjacency list and degrees
    for (const auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    // Min-heap for leaf nodes
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 1; i <= N; ++i)
    {
        if (degree[i] == 1)
            minHeap.push(i);
    }

    while (!minHeap.empty())
    {
        int node = minHeap.top();
        minHeap.pop();
        if (visited[node])
            continue;
        visited[node] = true;
        answer.push_back(node);

        // Remove the node and update degrees
        for (int neighbor : adj[node])
        {
            if (visited[neighbor])
                continue;
            degree[neighbor]--;
            if (degree[neighbor] == 1)
                minHeap.push(neighbor);
        }
    }

    return answer;
}
