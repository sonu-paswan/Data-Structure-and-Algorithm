#include <iostream>
#include <list>
using namespace std;
void addEdge(list <int> v[],int a,int b){
    v[a].push_back(b);
    // v[b].push_back(a);
}
bool *visited=new bool[6];

void DFS(list <int> vtx[],int v){
    visited[v]=true;
    cout<<v<<" ";
    list<int>::iterator i;
    for(i=vtx[v].begin();i!=vtx[v].end();i++){
        if(visited[*i]!=true){
            DFS(vtx,*i);
        }
    }
}
int main()
{   int count = 6;
    list<int> v[count];
    for(int i=0;i<6;i++){
        visited[i]=false;
    }
    addEdge(v,0,1);
    addEdge(v,0,5);
    addEdge(v,1,2);
    addEdge(v,1,3);
    addEdge(v,2,3);
    addEdge(v,3,4);
    DFS(v,0);
    return 0;
}