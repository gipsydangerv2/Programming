#include<iostream>
#include<climits>
using namespace std;
int cuttingRod(int val[],int n){
  int table[n+1];
  table[0]=0;
  for(int i=1;i<=n;i++){
    int max_val = INT_MIN;
    for(int j=0;j<i;j++){
      max_val = max(max_val,val[j]+table[i-j-1]);
    }
    table[i] = max_val;
  }
  return table[n];
}
int main(){
  //cuttingRod(val,len);
  return 0;
}
