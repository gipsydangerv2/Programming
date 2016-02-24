#include<iostream>
#include<string>
using namespace std;
int editDistance(string input1,string input2,int m,int n){
  int table[m+1][n+1];
  for(int i=0;i<=m;i++){
    for(int j=0;j<=n;j++){
      if(i==0) table[i][j] = j;
      if(j==0) table[i][j] = i;
      else if(input1[i-1] == input2[j-1])
        table[i][j] = table[i-1][j-1];
      else
        table[i][j] = 1 + min(min(table[i-1][j],table[i][j-1),table[i-1][j-1]);
    }
  }
  return table[m][n];
}
int main(){
  string input1,input2;
  cin >>input1>>input2;
  int m = input1.length();
  int n = input2.length();
  int ans = editDistance(input1,input2,m,n);
  cout<<"Edit Distance:"<<ans<<endl;
  return 0;
}
