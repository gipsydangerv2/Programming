#include<iostream>
#include<string>
using namespace std;
int lcs(string input1,string input2,int len1,int len2){
  int table[len1+1][len2+1];
  for(int i=0;i<=len1;i++){
    for(int j=0;j<=len2;j++){
      if(i==0 || j==0)
        table[i][j] = 0;
      else if(input1[i-1] != input2[j-1])
        table[i][j] = max(table[i-1][j],table[i][j-1]);
      else
        table[i][j] = 1+table[i-1][j-1];
    }
  }
  return table[len1][len2];
}
int main(){
  //lcs(input1,input2,length1,length2);
  return 0;
}
