#include<iostream>
using namespace std;
int knapsack(int capacity,int w[],int p[],int n){
  int i,j;
  int table[n+1][capacity+1];
  for(int i=0;i<=n;i++){
    for(int j=0;j<=capacity;j++){
      if(i==0 || j==0)
        table[i][j] = 0;
      else if(w[i-1] <= j)
        table[i][j] = max(table[i-1][j-w[i-1]]+p[i-1],table[i-1][j]);
      else
        table[i][j] = table[i-1][j];
    }
  }
  return table[n+1][capacity+1];
}
int main(){

}
