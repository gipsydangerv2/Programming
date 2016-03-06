/*
  This is a solution to m coloring problem.
*/
#include<iostream>
#define v 4
using namespace std;
bool isSafe(int vert,int c,int color[],int graph[][v]){
	for(int j=0;j<v;j++){
		if(graph[vert][j]==1 && c==color[j])
			return false;
	}
	return true;
}
bool mColoring(int vert,int color[],int m,int graph[][v]){
	if(vert==v)
		return true;
	else{
		for(int i=1;i<=m;i++){
			if(isSafe(vert,i,color,graph)){
				color[vert] = i;
				if(mColoring(vert+1,color,m,graph))
					return true;
				else
					color[vert] = 0;
			}
		}
		return false;
	}
}
int main(){
	int graph[v][v]={{0, 1, 1, 1},{1, 0, 1, 0},{1, 1, 0, 1},{1, 0, 1, 0}};
	int color[v] = {0};
	int m = 3;
	if(mColoring(0,color,m,graph)){
		for(int i=0;i<v;i++)
			cout<<color[i]<<" "<<endl;
	}
	else
		cout<<"Coloring not possible "<<endl;
	return 0;
}
