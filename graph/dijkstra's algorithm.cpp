#include <iostream>
#include<limits>
using namespace std;

// single source shortest path

// dijkstra's program for undirected graph
const int V = 8;
void dijkstra(int graph[V][V],int source){
    int Min,u;

    // distance array
    int *d=new int[V];
    // set array for marking visited or not 
    bool *s=new bool[V];
    for(int i=0;i<V;i++){
        d[i]=INT_MAX;
        s[i]=false;
    }
    d[source]=0;
    for(int i=0;i<V;i++){
        // extracting minimum
            Min=INT_MAX;
        for(int j=0;j<V;j++){
            if((d[j]<Min)&&(s[j]!=true)){
                Min=d[j];
                u=j;
            }
        }
        s[u]=true;
        for(int k=0;k<V;k++){
            if((graph[u][k])&&(s[k]!=true)&&(d[u]+graph[u][k]<d[k])&&d[u]!=INT_MAX){
                d[k]=d[u]+graph[u][k];
            }
        }
    }
    for(int i=0;i<V;i++){
        cout<<d[i]<<" ";
    }
}
int main()
{
    // creating graph
    int graph[V][V] = {{0,10,15,0,0,0,0,0},
                        {10,0,0,3,5,5,0,0},
                        {15,0,0,0,0,0,20,0},
                        {0,3,0,0,1,0,0,0},
                        {0,5,0,1,0,8,0,6},
                        {0,5,0,0,8,0,10,20},
                        {0,0,20,0,0,10,0,0},
                        {0,0,0,0,6,20,0,0}};
    
    dijkstra(graph,0);
    return 0;
}