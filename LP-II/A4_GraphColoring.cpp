#include <iostream>
#include <set>
using namespace std;

int color[101]; // Global color array

bool isSafe(int node, bool graph[101][101], int n, int col)
{
    for (int k = 0; k < n; k++)
    {
        if (k != node && graph[k][node] && color[k] == col)
        {
            return false;
        }
    }
    return true;
}

int getBound(int m, int N, int node, bool graph[101][101])
{
    set<int> usedColors;
    for (int i = 0; i < N; i++)
    {
        if (graph[node][i] && color[i] != 0)
        {
            usedColors.insert(color[i]);
        }
    }
    return m - usedColors.size();
}

bool solve(int node, int m, int N, bool graph[101][101])
{
    if (node == N)
    {
        return true;
    }
    // iterating to assign colors
    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, graph, N, i))
        {
            color[node] = i;
            int bound = getBound(m, N, node, graph);
            if (bound >= 0)
            {
                if (solve(node + 1, m, N, graph))
                    return true;
            }
            //backtracking
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int N)
{
    for (int i = 0; i < N; i++)
    {
        color[i] = 0;
    }

    if (solve(0, m, N, graph))
        return true;
    return false;
}

int main()
{
    int N, E, m;
    cout << "Enter number of nodes: ";
    cin >> N;
    cout << "Enter number of edges: ";
    cin >> E;
    cout << "Enter number of colors: ";
    cin >> m;

    bool graph[101][101];
    for(int i=0; i<101; i++)
    {
        for(int j=0; j<101; j++)
        {
            graph[i][j]=0;
        }
    }

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cout << "Enter source: ";
        cin >> u;
        cout << "Enter destination: ";
        cin >> v;
        graph[u][v] = true;
        graph[v][u] = true;
    }

    bool result = graphColoring(graph, m, N);
    if (result)
    {
        cout << "The Graph can be colored with " << m << " colors" << endl;
        cout << "Node colors: "<<endl;
        for (int i = 0; i < N; i++)
        {
            cout << "Node " << i << ": Color " << color[i] << endl;
        }
    }
    else
    {
        cout << "The Graph cannot be colored with " << m << " colors" << endl;
    }
}
