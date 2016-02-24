/*
  This is the solution to Longest Increasing Subsequence Problem. This is O(n^2) solution.But O(n*logn) solution also exist.
*/

#include<iostream>
#include<string>
using namespace std;
int LIS(int arr[],int n){
  int lis[n];
  for(int i=0;i<n;i++)
    list[i]=1;
  for(int i=1;i<n;i++)
    for(int j=0;j<i;j++){
      if(arr[j]<arr[i] && lis[i]<lis[j]+1)
        lis[i] = lis[j]+1;
    }
  int max=-1;
  for(int i=0;i<n;i++){
    if(max<lis[i])
      max=lis[i];
  }
  return max;
}
int main(){
  //int arr[];n:length of the array
  int ans = LIS(arr,n);
  return 0;
}
