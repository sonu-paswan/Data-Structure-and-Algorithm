// bfs in graph using cpp

#include <bits/stdc++.h>
using namespace std;
void addLink(list <int> v[],int a,int b){
    v[a].push_back(b); // one direction link 
    // vec[b].push_back(a);
}
void BFS(list <int> v[],int size,int start)
{
    bool *visited=new bool[size];
    int vertex;
    for(int i=0;i<size;i++){
        visited[i]=false;
    }
    list <int> q; // empty queue
    list <int>::iterator i; // iterater for traversing list 
    q.push_back(start);
    visited[start]=true;
    while(!q.empty()){
        vertex=q.front();
        cout<<vertex<<" ";
        q.pop_front();
        for( i=v[vertex].begin();i!=v[vertex].end();i++){
            if(visited[*i]==false){
                visited[*i]=true;
                q.push_back(*i);
                
            }
        }
    }
}
int main()
{   
    int count=4;
    list <int> v[count]; // array of empty list 
    addLink(v,0,1);
    addLink(v,0,2);
    addLink(v,1,2);
    addLink(v,2,0);
    addLink(v,2,3);
    addLink(v,3,3);
    int start=2;
    BFS(v,count,start);
    return 0;
}