/*
  In this possible to move left,right,diagonally downward.
*/
#include<iostream>
using namespace std;
int r,c;
int minCost(int cost[r][c],int m,int n){
  int table[r][c];
  table[0][0] = cost[0][0];
  for(int i=1;i<r;i++)  // to fill the leftmost column as only way is to move downwards.
    table[i][0] = table[i-1][0] + cost[i][0];
  for(int j=1;j<c;j++)  // to fill the topmost row as only way to reach is to move left.
    table[0][j] = table[0][j-1] + cost[0][j];
  for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++){
      int min_val = min(table[i-1][j-1],min(table[i-1][j],table[i][j-1]));
      table[i][j] = min_val + cost[i][j];
    }
  return table[m][n];
}
int main(){
  //minCost(cost,m,n);
}
