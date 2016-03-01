/*
  Given pair of chain.In each pair first element is smaller than the second element. for ex (a,b) and (c,d). A pair can follow 
  another pair if b < c. You have to find the length of longest such chain available. 
*/
#include<iostream>
#include<vector>
int maxChainLength(vector<pair<int,int>>vec,int n){
  vector<int>table(n,1);
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      pair<int,int>p1 = vec[j];
      pair<int,int>p2 = vec[i];
      if(p1.second < p2.first && table[i] < table[j] + 1)
        table[i] = table[j] + 1;
   }
  }
  int max_val =0;
  for(int i=0;i<n;i++)
    if(table[i]>max_val) max_val = table[i];
  return max_val;
}
int main(){
  return 0;
}
