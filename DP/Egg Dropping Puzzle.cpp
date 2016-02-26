#include<iostream>
#include<climits>
using namespace std;
int eggDrop(int n,int k){
  int table[n+1][k+1];
  
  //if n=1 and floors = k ans is k
  for(int j=1;j<=k;j++)
    table[1][j]=j;
    
  //if floors =0 ans is 0
  for(int i=1;i<=n;i++)
    table[i][0] =0;
  int ans;
  for(int i=2;i<=n;i++){
    for(int j=1;j<=k;j++){
      int minval = INT_MAX;
      for(int x=1;x<=j;x++){
        ans = max(table[i-1][x-1],table[i][j-x]);
        if(ans<minval)
          minval = ans;
      }
      table[i][j] = 1+minval;
    }
  }
  return table[n][k];
}
int main(){
  int n,k;
  // eggDrop(n,k);
  return 0;
}
