/*
  You can choose a 3 or 5 or 10 in a move. You have to count the no of possible ways to reach a given score.
*/
include<iostream>
using namespace std;
int count(int sum){
  int table[4][sum+1];
  int wght[]={3,5,10};
  for(int i=0;i<=3;i++) table[i][0] = 1;
  for(int j=1;j<=sum;j++) table[0][j] = 0;
  for(int i=1;i<=3;i++)
    for(int j=1;j<=sum;j++){
      if(wght[i-1]>j)
        table[i][j] = table[i-1][j];
      else
        table[i][j] = table[i-1][j] + table[i][j-wght[i-1]];
    }
  return table[3][sum];
}
int main(){
  return 0;
}
