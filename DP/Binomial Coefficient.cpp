/*
  C(n,k) = C(n-1,k-1) + C(n-1,k)
  C(n,0) = 1 = C(n,n)
*/
#include<iostream>
using namespace std;
int binCoeff(int n,int k){
  int table[n+1][k+1];
  for(int i=0;i<=n;i++){
    for(int j=0;j<=min(i,k);j++){
      if(j==0 ||i==j)
        table[i][j] = 1;
      else
        table[i][j] = table[i-1][j-1] + table[i-1][j];
    }
  }
  return table[n][k];
}
int main(){


}
