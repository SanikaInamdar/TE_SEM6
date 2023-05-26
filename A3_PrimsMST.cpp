#include <iostream>
#define INT_MAX 2147483647

using namespace std;
int heuristic(int src, int dest)
{
    return abs(src-dest);
}
void prims(int graph[101][101], int N, int E)
{
    int min=INT_MAX;
    int x=0;
    int y=0;
    int edges=0;
    int selected[N];
    int minWeight=0;
    for(int i=0; i<N; i++)
    {
        selected[i]=0;
    }

    selected[0]=1;
    while(edges<N-1)
    {
        min=INT_MAX;
        x=0;
        y=0;

        for(int i=0; i<N; i++)
        {
            if(selected[i]==1)
            {
                for(int j=0; j<N; j++)
                {
                    if(selected[j]==0 && graph[i][j]!=0)
                    {
                        int total = graph[i][j];
                        if(total<min)
                        {
                            min=total;
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
        cout<<x<<" - "<<y<<": "<<graph[x][y]<<endl;
        minWeight+=graph[x][y];
        selected[y]=1;
        edges++;
    }
    cout<<"The weight of the Minimum Spanning Tree is: "<<minWeight;
}
int main()
{
    int N, E;
    cout << "Enter number of nodes: ";
    cin >> N;
    cout << "Enter number of edges: ";
    cin >> E;

    int graph[101][101];
    //initializing the graph with 0 values
    for(int i=0; i<101; i++)
    {
        for(int j=0; j<101; j++)
        {
            graph[i][j]=0;
        }
    }

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cout << "Enter source: ";
        cin >> u;
        cout << "Enter destination: ";
        cin >> v;
        cout << "Enter weight: ";
        cin >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
    cout<<"The MST edges are: "<<endl;
    prims(graph, N, E);

}