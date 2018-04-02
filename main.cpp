#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int setBits[31];
int arr[100001];
int mat[100001][32];
int binExp(int num,int power){
    if(power == 0)
        return 1;
    else{
        int half = (binExp(num,power / 2))%mod;
        if(power & 1)
            return (((half * half)%mod)*num)%mod;
        return ((half * half)%mod);
    }
}
void createMatrix(){
    for(int i=0;i<100001;i++)
        mat[i][0] = 0;
    for(int i=0;i<32;i++)
        mat[0][i] = 0;

    for(int i=1;i<100001;i++){
        for(int j=1;j<31;j++){
            if( j > i)
                break;
            else if(j == 1)
                mat[i][j] = (binExp(2,i-1));
            else if(i == j)
                mat[i][j] = (1 << j) - 1;
            else
                mat[i][j] = (2*mat[i-1][j])%mod;
        }
    }
    /*
    for(int i=0;i<32;i++){
        for(int j=0;j<32;j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }*/
}
int findHighestSetBit(int num){
    int setBit = 0,j=0;
    while(num){
        if(num & 1)
          setBit = j;
        num = num >> 1;
        j++;
    }
    return setBit + 1;
}
int updateSetBits(int num){
    int i = 0;
    while(num){
        if(num & 1)
            setBits[i]++;
        num = num >> 1;
        i++;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n;
    createMatrix();
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<31;i++)
            setBits[i] = 0;
        int finalOR = 0;
        long long int sum = 0;
        for(int i=0;i<n;i++){
            cin >> arr[i];
            finalOR |= arr[i];
        }
        //cout << finalOR << "\n";
        for(int i=0;i<n;i++){
            updateSetBits(arr[i]);
        }
        int maxSetBit =  findHighestSetBit(finalOR);
        //cout << "max set Bit :" << maxSetBit << endl ;

        /*for(int i=30;i>=0;i--){
            cout << setBits[i] << " ";
        }
        cout << endl;*/

        for(int i=1;i<=maxSetBit;i++){
            sum = (sum + (mat[n][setBits[i-1]] * (1 << i-1))%mod)%mod;
        }
        cout << sum << "\n";
    }
    return 0;
}
