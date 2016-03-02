/*
  This is the optimised version of Count the no of ways to reach a given score in a game.
  Here space used is O(sum) and earlier space used was O(4*sum).
*/
#include<iostream>
using namespace std;
int count(int sum){
  int table[sum+1];
  table[0] = 1;
  for(int i=3;i<=sum;i++) table[i] += table[i-3];
  for(int i=5;i<=sum;i++) table[i] += table[i-5];
  for(int i=10;i<=sum;i++) table[i] += table[i-10];
  return table[sum];
}
int main(){
  return 0;
}
