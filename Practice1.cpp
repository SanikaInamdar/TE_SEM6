#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
bool isSafe(int node, int color[], bool graph[101][101], int n, int col)
{
    for (int k = 0; k < n; k++)
    {
        if (k != node && graph[k][node] == 1 && color[k] == col)
        {
            return false;
        }
    }
    return true;
}
int getBound(int m, int N, int node, int color[], bool graph[101][101])
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
bool solve(int node, int color[], int m, int N, bool graph[101][101])
{
    if (node == N)
    {
        return true;
    }

    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, color, graph, N, i))
        {
            color[node] = i;
            int bound = getBound(m, N, node, color, graph);
            if(bound >=0)
            {
                if (solve(node + 1, color, m, N, graph))
                return true;
            }
            color[node] = 0;
        }
    }
    return false;
}
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int N)
{
    int color[N];
    for (int i = 0; i < N; i++)
    {
        color[i] = 0;
    }
    //solve(currentNode, colorArray, no.of colors(m), N, graph)
    if (solve(0, color, m, N, graph))
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
    //initializing the graph with 0 values
    memset(graph, false, sizeof graph);

    // Edges are (0, 1), (1, 2), (2, 3), (3, 0), (0, 2)
    // add edges in graph
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cout << "Enter source: ";
        cin >> u;
        cout << "Enter destination: ";
        cin >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    bool result = graphColoring(graph, m, N);
    if (result)
    {
        cout << "The Graoh can be colored with " << m << " colors" << endl;
    }
    else
    {
        cout << "The Graph cannot be colored with " << m << " colors" << endl;
    }
}