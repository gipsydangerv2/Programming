// This file contains code for Segment Tree with Lazy Propogation.
// The query function is for the sum of elements within a range[L,R];
// updateLazy and queryLazy are the functions to be used in case of Lazy Propogation.
# include<bits/stdc++.h>
using namespace std;
# define maxn 100001
# define ll long long
ll t[4*maxn];
int arr[maxn];
ll lazy[4*maxn];    // same size as segment tree t.
void build(int v,int start,int end){
    if(start == end)
        t[v]=arr[start];
    else{
        int mid = (start+end)/2;
        build(2*v,start,mid);
        build(2*v+1,mid+1,end);
        t[v]=t[v*2]+t[v*2+1];
    }
}
void update(int v,int start,int end,int idx,int val){
    if(start == end){
        t[v] += val;
    }
    else{
        int mid =(start+end)/2;
        if(idx<=mid)
            update(2*v,start,mid,idx,val);
        else
            update(2*v+1,mid+1,end,idx,val);
        t[v]=t[2*v]+t[2*v+1];
    }
}
ll query(int v,int start,int end,int l,int r){
    if(l>r)
        return 0;
    if(l==start && r==end)
        return t[v];
    else{
        int mid =(start+end)/2;
        return query(2*v,start,mid,l,min(r,mid)) +      
                query(2*v+1,mid+1,end,max(l,mid+1),r);
    }
}
void updateLazy(int v,int start,int end,int l,int r,int val){
    if(l>r)
        return;
    if(lazy[v]!=0){
        t[v] += (end-start+1)*lazy[v];
        if(start != end){
            lazy[2*v] += lazy[v];
            lazy[2*v+1] += lazy[v];
        }
        lazy[v]=0;
    }
    if(l==start && r==end){
        t[v] += (end-start+1)*val;
        if(start != end){
            lazy[2*v]+=val;
        return;
            lazy[2*v+1]+=val;
        }
    }
    int mid = (start+end)/2;
    updateLazy(2*v,start,mid,l,min(r,mid),val);
    updateLazy(2*v+1,mid+1,end,max(l,mid+1),r);
    t[v]=t[2*v]+t[2*v+1];
}
ll queryLazy(int v,int start,int end,int l,int r){
    if(l>r)
        return 0;
    if(lazy[v]!=0){
        t[v]+=(end-start+1)*lazy[v];
        if(start != end){
            lazy[2*v] += lazy[v];
            lazy[2*v+1] += lazy[v];
        }
        lazy[v]=0;
    }
    if(l==start && r==end)
        return t[v];
    int mid = (start+end)/2;
    return query(2*v,start,mid,l,min(r,mid))+
           query(2*v+1,mid+1,end,max(l,mid+1),r);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q,qtype,l,r;
    cin >> n >> q;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    build(1,0,n-1);
    for(int i=0;i<q;i++){
        cin >> qtype >> l >> r;
        // qtype:1 updateRange, qtype:2 queryRange
        if(qtype==1)
            updateLazy(1,0,n-1,l-1,r-1);
        else
            cout << queryLazy(1,0,n-1,l-1,r-1);
    }
    
    
    return 0;
}
