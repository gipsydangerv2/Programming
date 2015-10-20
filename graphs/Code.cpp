#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
void BFS_MODIFIED(vector<vector<int>>graph,int src){
    int v,d;
    queue<int>q;
    int distance[graph.size()][3];
    vector<bool>visited(graph.size(),false);
    for(int i=0;i<graph.size();i++){
        distance[i][0]=i;
        distance[i][1]=INT_MAX;
        distance[i][2]=0;
    }
    q.push(src);
    visited[src]=true;
    distance[src][1]=0;
    while(!q.empty()){
        v = q.front();
        q.pop();
        for(int i=0;i<graph.size();i++){
            if(graph[v][i]!=0){
                d = distance[v][1]+graph[v][i];
                if(distance[i][1]==INT_MAX){
                    distance[i][1]=d;
                    distance[i][2]=v;
                }
                if(distance[i][1]>d){
                    distance[i][1]=d;
                    distance[i][2]=v;
                }
                if(visited[i]==false){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
    }
    cout <<"the distance table is :"<<endl;
    cout <<"vertex distance path"<<endl;
    for(int i=0;i<graph.size();i++){
        cout <<distance[i][0]<<" "<<distance[i][1]<<" "<<distance[i][2]<<endl;
    }

}
int main(){
    int v,e,src,dest,wght;
    cout <<"Enter the number of vert and edges:";
    cin >>v>>e;
    vector<vector<int>>graph(v+1,vector<int>(v+1));
    cout <<"Enter the source and destination edges"<<endl;
    for(int i=0;i<e;i++){
        cin >>src>>dest>>wght;
        graph[src][dest]=wght;
        graph[dest][src]=wght;
    }
    cout <<"Enter the source vertex:"<<endl;
    cin >>src;
    BFS_MODIFIED(graph,src);
    return 0;
}
