/*
  This is All Pair Shortest Path Algorithm.
  Here dist[i][i] = 0 and graph[i][j] = INF if no edge exist between them.
  
  For every pair (i,j) we find the shortest path using k as the intermediate vertex.
  We initialise the dist matrix with the graph matrix.
  
  2 case arises
  1) If k is included then dist[i][j] = dist[i][k] + dist[k][j]
  2) If k is not included dist[i][j] remains unchanged.
  
*/
#include<iostream>
#include<climits>
int vert;
void floydWarshall(int graph[vert][vert]){
  int dist[vert][vert];
  for(int i=0;i<vert;i++)
    for(int j=0;j<vert;j++)
      dist[i][j] = graph[i][j];
  for(int i=0;i<vert;i++)
    for(int j=0;j<vert;j++)
      for(int k=0;k<vert;k++)
        if(dist[i][j] >dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
  cout<<"The All Pair Shortest Path Matrix is :"<<endl;
  for(int i=0;i<vert;i++){
    for(int j=0;j<vert;j++){
      cout<<dist[i][j]<<" ";
    }
    cout<<endl;
  }
  
}
int main(){
  cin >>vert;
  int graph[vert][vert];
  //floydWarshall(graph);
}
