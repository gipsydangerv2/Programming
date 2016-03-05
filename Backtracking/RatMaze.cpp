/*
This is the solution to rat maze problem.
*/
#include<iostream>
using namespace std;
int n=4;
bool isSafe(int i,int j,int matrix[4][4],int visited[4][4]){
	if(i>=0 && i<n && j>=0 && j<n && matrix[i][j]==1 && visited[i][j]==0)
		return true;
	return false;
}
bool solveMaze(int i,int j,int matrix[4][4],int visited[4][4]){
	if(i==n-1 && j == n-1)
		return true;
	else{
		// for right
		if(isSafe(i,j+1,matrix,visited)){
			visited[i][j+1] = 1;
			if(solveMaze(i,j+1,matrix,visited))
				return true;
			else 
				visited[i][j+1] = 0;
		}
		// for down
		if(isSafe(i+1,j,matrix,visited)){
			visited[i+1][j] = 1;
			if(solveMaze(i+1,j,matrix,visited))
				return true;
			else
				visited[i+1][j] = 0;
		}
		else
			return false;
	}
}
int main(){
	int n=4;
	int matrix[4][4]	={{1, 0, 0, 0},{1, 1, 0, 1},{0, 1, 0, 0},{1, 1, 1, 1}};
	int visited[4][4] = {0};
	visited[0][0] = 1;
	if(solveMaze(0,0,matrix,visited))
	{
		cout<<"Solution exist"<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<visited[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	else
		cout<<"No solution exist"<<endl;
	return 0;
}
