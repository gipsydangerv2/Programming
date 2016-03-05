/*
This is the solution to NQueen Problem.
*/
#include<iostream>
#include<cmath>
#define n 8
using namespace std;
bool isSafe(int i,int p,int pos[]){
	for(int j=0;j<i;j++){
		if(i==j || p==pos[j] || abs(i-j)== abs(p-pos[j]))
			return false;
	}
	return true;
}
bool nQueen(int i,int pos[]){
	if(i==n)
		return true;
	else{
		for(int j=0;j<n;j++){
			if(isSafe(i,j,pos)){
				pos[i] = j;
				if(nQueen(i+1,pos))
					return true;
				else
					pos[i] = -1;
			}
		}
		return false;
	}
}
int main(){
	int pos[n]={0};
	if(nQueen(0,pos))
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(j==pos[i]) cout<<"1 ";
				else cout<<"0 ";
			}
			cout<<endl;
		}
	else
		cout<<"No solution exists"<<endl;
	return 0;
}
