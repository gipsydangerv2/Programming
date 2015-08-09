#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;
void dfs(vector<list<int>>graph,int src){

    vector<bool>visited(graph.size(),false);
    stack<int>s;
    s.push(src);
    visited[src]=true;
    while(!s.empty()){
        src = s.top();
        cout <<src<<" ";
        s.pop();
        for(list<int>::iterator it=graph[src].begin();it!=graph[src].end();it++){
            if(visited[*it]==false){
                s.push(*it);
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
    cout <<"The depth first traversal is:";
    dfs(graph,src);
    return 0;
}
