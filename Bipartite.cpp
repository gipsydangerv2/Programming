/*
  code credits: Ankit Kumar
  created on :11/11/2015
  Graph is represented as adjacency list.
  This is the code to check whether a graph is bipartite or not.
  Two color : red and blue are used to color the vertices.
*/
#include<iostream>
#include<queue>
#include<list>
using namespace std;
int n,e,src,dest;
int fastInput(){
	int num =0;
	char ch = getchar();
	while(ch < 48 && ch > 57) ch = getchar();
	while(ch>=48 && ch<=57){
		num = (num << 3) + (num << 1) + ch - 48;
		ch = getchar();
	}
	return num;
}
bool bfs(vector<list<int>>graph){
	vector<bool>visited(n+1,false);
	vector<string>color(n+1);
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(visited[i]==false){
			visited[i] = true;
			color[i]="red";
			q.push(i);
			while(!q.empty()){
				int vertex = q.front();
				q.pop();
				for(list<int>::iterator it = graph[vertex].begin();it != graph[vertex].end();it++){
					if(visited[*it]==false){
						visited[*it] = true;
						if(color[vertex]=="red") 
							color[*it] = "blue";
						else if(color[vertex]=="blue")
							color[*it] = "red";
						q.push(*it);
					}
					else if(color[vertex]==color[*it]){
						return false;
					}
				}
			}
		}
	}
	return true;
}
int main(){
	cout<<"Enter vertices and edges:";
	n = fastInput();
	e = fastInput();
	vector<list<int>>graph(n+1);
	for(int j=1;j<=e;j++){
		src = fastInput();
		dest = fastInput();
		graph[src].push_back(dest);
		graph[dest].push_back(src);
	}
	bool ans = bfs(graph);
	if(ans) printf("Graph is bipartite");
	else printf("Graph is not bipartite");
		
	return 0;
}
