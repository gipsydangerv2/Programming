#include <bits/stdc++.h>
using namespace std;
# define ll long long
int calcPower(ll num,int p){
    int cnt = 0;
    while(num%p==0){
        num = num/(2LL);
        cnt++;
    }
    return cnt;
}
ll calcTrailingZero(ll first,ll second,int n){
        ll power2 = 0;
        ll num1pow2 = 0,num1pow5=0,num2pow2=0,num2pow5=0;
        if(first == 0 && n==0)
            return 1;
        else if(second == 0 && n == 1)
            return 1;
        else if(first == 0 || second == 0){
            return 1;
        }
        num1pow2 = calcPower(first,2);
        num1pow5 = calcPower(first,5);

        num2pow2 = calcPower(second,2);
        num2pow5 = calcPower(second,5);

        if(n==0 || n==1){
            if(n==0)
                return min(num1pow2,num1pow5);
            else
                return min(num2pow2,num2pow5);
        }
        ll respow2 =0LL,respow5 = 0LL;
        for(int i=2;i<=n;i++){
            respow2 = num1pow2 + num2pow2;
            respow5 = num1pow5 + num2pow5;
            num1pow2 = num2pow2;
            num1pow5 = num2pow5;
            num2pow2 = respow2;
            num2pow5 = respow5;
        }
        return min(respow2,respow5);
}
int main()
{
    ll first,second,result;
    int n,cnt=0;
    cin >> first >> second >> n;
    cout << "ans:" << calcTrailingZero(first,second,n);

    return 0;
}
