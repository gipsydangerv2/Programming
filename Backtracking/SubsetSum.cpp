/*This code is for subset sum using backtracking.*/
#include<iostream>
#define ARRAYSIZE(a) (sizeof(a))/(sizeof(a[0]))
using namespace std;
bool subsetSum(int csum,int n,int i,int k,int w[],int subset[]){
	if(csum == k)
		return true;
	else{
		for(int j=i;j<n;j++){
			if(csum+w[j]<=k){
				csum += w[j];
				subset[j] = 1;
				if(subsetSum(csum,n,j+1,k,w,subset))
					return true;
				else{
					csum -= w[j];
					subset[j] = 0;
				}
			}
		}
		return false;
	}
}
int main(){
	int weights[] = {15, 22, 14, 26, 32, 9, 16, 8};
    int size = ARRAYSIZE(weights);
    int subset[size]={0};
    if(subsetSum(0,size,0,53,weights,subset)){
    	cout<<"Solution exists:"<<endl;
    	for(int i=0;i<size;i++){
    		if(subset[i])
    			cout<<weights[i]<<" ";
		}
	}
	else
		cout<<"no solution exists"<<endl;
	return 0;
}
