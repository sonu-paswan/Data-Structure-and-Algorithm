#include <iostream>
#include <limits>
using namespace std;

// single source shortest path

// dijkstra's program for undirected graph
const int V = 9;
void dijkstra(int graph[V][V], int source)
{
    int Min, u;

    // distance array
    int *d = new int[V];
    // set array for marking visited or not
    bool *s = new bool[V];
    // for path 
    int *path=new int[V];

    for (int i = 0; i < V; i++)
    {
        d[i] = INT_MAX;
        s[i] = false;
        path[i]=INT_MAX;
    }
    d[source] = 0;
    for (int i = 0; i < V; i++)
    {
        // extracting minimum
        Min = INT_MAX;
        for (int j = 0; j < V; j++)
        {
            if ((d[j] < Min) && (s[j] != true))
            {
                Min = d[j];
                u = j;
            }
        }
        s[u] = true;
        for (int k = 0; k < V; k++)
        {
            if ((graph[u][k]) && (s[k] != true) && (d[u] + graph[u][k] < d[k]) && d[u] != INT_MAX)
            {
                d[k] = d[u] + graph[u][k];
                path[k]=u;
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        cout << d[i] << " ";
    }
    cout<<endl<<"enter destination :";
    int j;
    cin>>j;
    cout<<"path :";
    do{
        cout<<j<<"<-";
        j=path[j];
    }while(j!=INT_MAX);
}
int main()
{
    // creating graph
    int graph[V][V] = {{0,4,0,0,8,0,0,0,0},
                       {4,0,8,0,11,0,0,0,0},
                       {0,8,0,7,0,0,4,0,2},
                       {0,0,7,0,0,0,14,9,0},
                       {8,11,0,0,0,1,0,0,7},
                       {0,0,0,0,1,0,2,0,6},
                       {0,0,4,14,0,2,0,10,0},
                       {0,0,0,9,0,0,10,0,0},
                       {0,0,2,0,7,6,0,0,0}};
    int source=8;
    dijkstra(graph, source);
    return 0;
}