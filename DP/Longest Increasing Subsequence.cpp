/*
  This is the solution to Longest Increasing Subsequence Problem. This is O(n^2) solution.But O(n*logn) solution also exist.
*/

#include<iostream>
#include<climits>
using namespace std;
int LIS(int arr[],int n){
  int table[n];
  for(int i=0;i<n;i++) arr[i] = 1;
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      if(arr[i]>arr[j] && table[i] < table[j] + 1)
        table[i] = table[j] + 1;
    }
  }
  int max_val = INT_MIN;
  for(int i=0;i<n;i++){
    if(table[i]>max_val)
     max_val = table[i];
  }
  return max_val;
}
