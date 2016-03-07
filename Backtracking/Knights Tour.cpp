/*
  This problem is about knight tour. Whether a knight can cover all the blocks on a chess board visiting each block only once.
*/
#include<iostream>
using namespace std;
int squareLeft =64;
int n=8;
int m1[] = {-1,-1,-2, -2, 1,1,2,2};
int m2[] = {-2,2, -1,1, -2,2, -1,1};

bool valid(int x, int y)
{
	if(x < 0 || y < 0)
		return false;
	if(x > 7 || y > 7)
		return false;
	return true;
}

bool knightTour(int i,int j,int squareLeft,int visited[8][8]){
	if(squareLeft==0){
		return true;
	}
	else{
		for(int xx = 0; xx < 8; xx++)
		{	int x = i+m1[xx], y = j+m2[xx];
			if(valid(x, y) && !visited[x][y] )
			{
				visited[x][y] = 1;
				//bool result = false;
				bool result = knightTour(x, y, squareLeft-1, visited);
				if(result)
					return true;
				visited[x][y] = 0;
			}
		}
	}
	
	return false;
}
int main(){
	int visited[8][8];
	for(int j=0;j<8;j++)
		for(int k=0;k<8;k++) 
			visited[j][k] = 0;
	visited[0][0] = 1;
	if(knightTour(0,0,63,visited))
		cout<<"successful solution found"<<endl;
	else
	 	cout<<"no solution exist"<<endl;
	return 0;
}
