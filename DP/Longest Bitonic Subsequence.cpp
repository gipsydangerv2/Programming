#include<iostream>
#include<climits>
using namespace std;
int LBS(int arr[],int n){
  int LIS[n],LDS[n];
  for(int i=0;i<n;i++){
    LIS[i] = 1;
    LDS[i] = 1;
  }
  // compute LIS from left to right.
  for(int i=1;i<n;i++)
    for(int j=0;j<i;j++){
      if(arr[i] > arr[j] && LIS[i] < LIS[j] + 1)
        LIS[i] = LIS[j] + 1;
    }
    
  // compute LDS from right to left.
  for(int i=n-2;i>=0;i--)
    for(int j=n-1;j>i;j--){
      if(arr[i] > arr[j] && LDS[i] < LDS[j] + 1)
        LDS[i] = LDS[j] + 1;
    }
  int max_val = INT_MIN;
  for(int i=0;i<n;i++){
    if(max_val<LIS[i]+LDS[i]-1)
      max_val = LIS[i]+LDS[i]-1;
  }
  return max_val;
}
int main(){
  //LBS(arr,length);
}
