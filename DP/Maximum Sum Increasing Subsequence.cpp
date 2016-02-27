/* This is a variation of Maximum Sum Increasing Subsequence. Here more focus on sum. */

#include<iostream>
#include<climits>
using namespace std;
int MSIS(int arr[],int n){
  int table[n];
  for(int i=0;i<n;i++)
    table[i] = arr[i];
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      if(arr[i]>arr[j] && table[i] < table[j] + arr[i])
        table[i] = table[j] + arr[i];
    }
  }
  int max_sum = INT_MIN;
  for(int i=0;i<n;i++){
    if(table[i]>max_sum)
      max_sum = table[i];
  }
  return max_sum;
}
int main(){
  return 0;
}
