#include<iostream>
#include<string>
using namespace std;
void printPermutation(string str){
  cout<<str<<endl;
}
void permute(string str,int i){
  int n = str.length();
  if(i==n)
    printPermutation(str);
  else{
    for(int j=i;j<n;j++){
      swap(str[i],str[j]);
      permute(str,i+1);
      swap(str[i],str[j]);
    }
  }
}
int main(){
  permute("abc",0);
  return 0;
} 
