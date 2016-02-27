#include<iostream>
#include<climits>
using namespace std;
int matrixChain(int dim[],int n){
  int table[n][n];
  for(int i=1;i<n;i++)
    table[i][i] = 0;
  for(int L=2;L<n;L++){
    for(int i=1;i<=n-L+1;i++){
      int j = i+L-1;
      int min_val = INT_MAX;
      for(int k=i;k<=j-1;k++){
        min_val = min(min_val,table[i][k] + table[k][j] + dim[i-1] * dim[k] * dim[j]);
      }
      table[i][j] = min_val;
    }
  }
  return table[1][n-1];
}
int main(){
  return 0;
}
