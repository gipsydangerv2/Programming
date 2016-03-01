/*
  Partition problem is that can we divide an array into 2 parts such that the sum of elements in both parts is same.
*/
#include<iostream>
using namespace std;
bool findPartition(int arr[],int n){
  int sum =0;
  for(int i=0;i<n;i++) sum += arr[i];
  
  if(sum % 2 == 1) return false;
  int table[n+1][sum/2+1];
  for(int i=0;i<=n;i++)
    table[i][0] = true;
  for(int j=1;j<=sum/2;j++)
    table[0][j] = false;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=sum/2;j++){
      if(arr[i-1] > j)
        table[i][j] = table[i-1][j];
      else
        table[i][j] = table[i-1][j] || table[i-1][j-arr[i-1]];
    }
  }
  return table[n][sum/2];
}
int main(){
  return 0;
}
