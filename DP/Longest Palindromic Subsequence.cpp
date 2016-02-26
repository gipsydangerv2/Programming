#include<iostream>
#include<string>
using namespace std;
int LPS(string input,int n){

  int table[n][n];
  int j;
  for(int i=0;i<n;i++)
    table[i][i] = 1;
  for(int l=2;l<=n;l++){
    for(int i=0;i<n-l+1;i++){
      j = i+l-1;
      if(input[i] == input[j] && l==2)
        table[i][j] = 2;
      if(input[i] == input[j])
        table[i][j] = 2 + table[i+1][j-1];
      else
        table[i][j] = max(table[i+1][j],table[i][j-1]);
    }
  }
  return table[0][n-1];
}
int main(){
  string input;
  cin >>input;
  //lps(input,input.length());
  return 0;
}
