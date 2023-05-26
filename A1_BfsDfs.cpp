#include<iostream>
#include<vector>
#include<queue>

using namespace std;
//dfs of graph
void dfs(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";
    for (int u : adj[s])
    {
        if (visited[u] == false)
        {
            dfs(adj, u, visited);
        }
    }
}
//bfs of graph
void bfs(vector<int> adj[], int s, bool visited[])
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u])
        {
            if (visited[v] == false)
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
//function to add edge
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
//main function
int main()
{
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;
    vector<int> adj[n];
    bool visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    cout << "Enter edges: ";
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }
    cout << "DFS: ";
    dfs(adj, 0, visited);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    cout << "BFS: ";
    bfs(adj, 0, visited);
    cout << endl;
    return 0;
}
