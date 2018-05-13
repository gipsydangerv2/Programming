# include<bits/stdc++.h>
using namespace std;
# define ll long long
# define maxn 100001
struct query{
    int l,r;
    int idx;
};
struct query queries[maxn];
int arr[maxn];
map<int,int> cnt;
ll res[maxn];
int block_size = 0;
ll sum = 0LL;
bool compare(const query & q1,const query &q2){
    if(q1.l/block_size == q2.l/block_size)
        return q1.r < q2.r;
    return q1.l/block_size < q2.l/block_size;
}
void add(int idx){
    int v = arr[idx];
    cnt[v]++;
    if(cnt[v]%2==0)
        sum = sum - v*(cnt[v]-1);
    else
        sum = sum + v*(cnt[v]);
}
void subtract(int idx){
    int v=arr[idx];
    cnt[v]--;
    if(cnt[v]%2==0)
        sum = sum - v*(cnt[v]+1);
    else
        sum = sum + v*(cnt[v]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q,l,r,idx;
    cin >> n;
    block_size = sqrt(n*1.0);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> l >> r;
        queries[i].l = l-1;
        queries[i].r = r-1;
        queries[i].idx = i;
    }
    sort(queries,queries+q,compare);
    int curr_left = 0,curr_right = -1;
    for(int i=0;i<q;i++){
        l = queries[i].l;
        r = queries[i].r;
        idx = queries[i].idx;
        while(curr_right<r){
            curr_right++;
            add(curr_right);
        }
        while(curr_right>r){
            subtract(curr_right);
            curr_right--;
        }
        while(curr_left<l){
            subtract(curr_left);
            curr_left++;
        }
        while(curr_left>l){
            curr_left--;
            add(curr_left);
        }
        res[idx] = sum;
    }
    for(int i=0;i<q;i++){
        cout << res[i] << "\n";
    }
    return 0;
}
