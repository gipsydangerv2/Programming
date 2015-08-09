#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
void bfs(vector<list<int>>graph,int src){

    vector<bool>visited(graph.size(),false);
    queue<int>q;
    q.push(src);
    visited[src]=true;
    while(!q.empty()){
        src = q.front();
        cout <<src<<" ";
        q.pop();
        for(list<int>::iterator it=graph[src].begin();it!=graph[src].end();it++){
            if(visited[*it]==false){
                q.push(*it);
                visited[*it]=true;
            }
        }
    }
}
int main(){
    int v,e,src,dest;
    cout <<"Enter the number of vertexes and edges:";
    cin >>v>>e;
    vector<list<int>>graph(v+1);
    cout <<"Enter the src to dest edge"<<endl;
    for(int i=0;i<e;i++){
        cin >>src>>dest;
        graph[src].push_back(dest);
        graph[dest].push_back(src);
    }
    cout <<"Enter the source vertex:";
    cin >>src;
    cout <<"The breadth first traversal is:";
    bfs(graph,src);
    return 0;
}
