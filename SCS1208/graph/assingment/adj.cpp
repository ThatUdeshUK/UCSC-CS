#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
queue<int> q;

void resetVisited(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        visited[i] = false;
    }
}

void addEdge(int from, int to)
{
    graph[from].push_back(to);
}

void bfs(int from)
{
    q.push(from);
    while (q.size() > 0)
    {
        int val = q.front();
        cout << val << ", ";
        visited[val] = true;
        q.pop();
        vector<int> line = graph[val];
        // cout << line.size() << " ";
        for (size_t i = 0; i < line.size(); i++)
        {
            if (visited[line[i]] == false) {
                // cout << line[i] << "sex";
                q.push(line[i]);
            }
        }
    }
}

void dfs(int from)
{
    if (visited[from] == true)
    {
        return;
    }
    cout << from << ", ";
    visited[from] = true;
    vector<int> line = graph[from];
    int i;
    for (i = 0; i < line.size(); i++)
    {
        dfs(line[i]);
    }
}

int main()
{
    graph.reserve(10);
    visited.reserve(10);
    addEdge(0, 1);
    addEdge(0, 3);
    addEdge(1, 2);
    addEdge(2, 5);
    addEdge(2, 3);
    addEdge(5, 0);
    resetVisited(10);
    dfs(0);
    cout << endl << "--------" << endl;
    resetVisited(10);
    bfs(0);
    return 0;
}
