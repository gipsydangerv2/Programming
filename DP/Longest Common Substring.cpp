#include<iostream>
#include<string>
using namespace std;
int lcstring(string input1,string input2,int m,int n){
  int table[m+1][n+1];
  for(int i=0;i<=m;i++){
    for(int j=0;j<=n;j++){
      if(i==0 || j==0)
        table[i][j] = 0;
      else if(input1[i-1] == input2[j-1])
        table[i][j] = 1 + table[i-1][j-1];
      else 
        table[i][j] = 0;
    }
  }
  return table[m][n];
}
int main(){
  // lcSubstring(string1,string2,length1,length2);
}
