/*
A path is an undirected graph is called a hamiltonian path if each vertex is visited exacly once.A Hamiltonian Cycle is a 
hamiltonian path with the last vertex having edge to the first.
*/
#include<iostream>
#define v 5
using namespace std;
// to check whether the vertex has been visited or not
bool isSafe(int vert,int path[]){
	for(int i=0;i<v;i++){
		if(path[i]==vert) return false;
	}
	return true;
}
void printPath(int path[]){
	for(int i=0;i<v;i++){
		cout<<path[i]<<" ";
		
	}
		
}
bool hamiltonianCycle(int vert,int pos,int path[],int graph[v][v]){
	if(pos==v)
		return true;
	else{
		for(int i=0;i<v;i++){
			if(graph[vert][i] && isSafe(i,path)){
				path[pos] = i;
				if(hamiltonianCycle(i,pos+1,path,graph))
					return true;
				else
					path[pos] = -1;
			}
		}
		return false;
	}
}
int main(){
	int graph1[v][v] = {{0, 1, 0, 1, 0},{1, 0, 1, 1, 1},{0, 1, 0, 0, 1},{1, 1, 0, 0, 1},{0, 1, 1, 1, 0}};
	int graph2[v][v] = {{0, 1, 0, 1, 0},{1, 0, 1, 1, 1},{0, 1, 0, 0, 1},{1, 1, 0, 0, 0},{0, 1, 1, 0, 0}};
	int path[v] ={-1};
	path[0] = 0;
	bool ans = hamiltonianCycle(0,1,path,graph1);
	if(ans) printPath(path);
	else cout<<"\nNo cycle exist"<<endl;
	path[0] = 0;
 	ans = hamiltonianCycle(0,1,path,graph2);
 	if(ans) printPath(path);
 	else cout<<"\n No cycle exist"<<endl;
	return 0;
}
