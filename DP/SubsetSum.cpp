#include<iostream>
using namespace std;
int SubsetSum(int sum,int w[],int n){
  int table[n+1][sum+1];
  for(int i=0;i<=n;i++){
    for(int j=0;j<=sum;j++){
      if(j==0) 
        table[i][j] = 1;
      else if(i==0 && j!=0) 
        table[i][j]=0;
      else if(w[i-1] > j)
        table[i][j] = table[i-1][j];
      else 
        table[i][j] = table[i-1][j-w[i-1]] || table[i-1][j];
    }
  }
  return table[n+1][sum+1];
}
int main(){
  int set[] ={1,2,3,4,5,6};
  int sum = 10;
  int ans = SubsetSum(sum,set,6);
  if(ans)
    cout <<"There exists a subset with the given sum";
  else 
    cout <<"There does not exist a subset with the given sum";
  return 0;
}
