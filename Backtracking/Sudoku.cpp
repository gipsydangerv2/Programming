/*
This is used to solve sudoku game using backtracking.
*/
#include<iostream>
#define v 9
using namespace std;
bool checkRow(int col,int num,int grid[v][v]){
	for(int i=0;i<v;i++)
		if(grid[i][col]==num) return false;
	return true;
}
bool checkColumn(int row,int num,int grid[v][v]){
	for(int j=0;j<v;j++)
		if(grid[row][j]==num) return false;
	return true;
}
bool checkBox(int row,int col,int num,int grid[v][v]){
	int r = row/3;
	int c = col/3;
	int box = r*3 + c;
	int x_pos[9]={0,0,0,3,3,3,6,6,6};
	int y_pos[9]={0,3,6,0,3,6,0,3,6};
	int x = x_pos[box];
	int y = y_pos[box];
	for(int i=x;i<x+3;i++)
		for(int j=y;j<y+3;j++)
			if(grid[i][j]==num) return false;
	return true;
}
bool isSafe(int row,int col,int num,int grid[v][v]){
	if(!checkRow(col,num,grid) || !checkColumn(row,num,grid) || !checkBox(row,col,num,grid)) 
		return false;
	return true;
}
bool findEmptyCell(int grid[v][v],int *r,int *c){
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			if(grid[i][j]==0){
				*r = i,*c =j;
				return true;
			}
	return false;
}
bool solveSudoku(int grid[v][v]){
	int row =0,col=0;
	if(!findEmptyCell(grid,&row,&col))
		return true;
	else{
		for(int num=1;num<=v;num++){
			if(isSafe(row,col,num,grid)){
				grid[row][col] = num;
				if(solveSudoku(grid))
					return true;
				else{
					grid[row][col] = 0;
				}
			}
		}
		return false;
	}
}
int main(){
	int grid[v][v] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if(solveSudoku(grid)){
    	for(int i=0;i<v;i++){
    		for(int j=0;j<v;j++){
    			cout<<grid[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
