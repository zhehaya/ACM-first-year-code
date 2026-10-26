#include<bits/stdc++.h>
#define int long long 
#define N 145141
#define INF 1145141919810
using namespace std;
namespace SEG{//权值线段树//存储为最早下标
    struct node{
        int v;
        int ls,rs;}tree[N*35];
    int cnt;
    int newnode(int val){
        ++cnt;
        tree[cnt].v=val;
        return cnt;
    }
    int push_up(int nowid){
        tree[nowid].v=min(tree[tree[nowid].ls].v,tree[tree[nowid].rs].v);
    }
    void insert(int nowid,int l,int r,int id,int val){
        if(l==r) {
            tree[nowid].v=id;return;
        }
        int mid=(l+r)>>1;
        if(val<=mid){
            if(tree[nowid].ls==0) tree[nowid].ls=newnode(id);
            insert(tree[nowid].ls,l,mid,id,val);
        }else{
            if(tree[nowid].rs==0) tree[nowid].rs=newnode(id);
            insert(tree[nowid].rs,mid+1,r,id,val);
        }
        push_up(nowid);
    }
    int query(int nowid,int l,int r,int L,int R){
       
        if(l>=L&&r<=R) {
             //cout<<l<<" "<<r<<" "<<tree[nowid].v<<":"<<L<<" "<<R<<endl;
            //cout<<tree[nowid].v<<endl;
            return tree[nowid].v;
        }
        int mid=(l+r)>>1;
        int res=INF;
        if(L<=mid&&tree[nowid].ls!=0){
            res=min(res,query(tree[nowid].ls,l,mid,L,R));
        }
        if(R>mid&&tree[nowid].rs!=0){
            res=min(res,query(tree[nowid].rs,mid+1,r,L,R));
        }
        push_up(nowid);
         //cout<<l<<" "<<r<<" "<<tree[nowid].v<<":"<<L<<" "<<R<<endl;
        //cout<<res<<endl;
        return res;
    }
}
int st[N][30];
int n,q;
int a[N];
int k;
signed main()
{
    
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    SEG::tree[0].v=INF;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cin>>k;
    SEG::newnode(INF);
    SEG::insert(1,-1e9,1e9,n+1,1e9);
    for(int i=n;i>=1;i--){
        st[i][0]=min(SEG::query(1,-1e9,1e9,-1e9,a[i]-k-1),SEG::query(1,-1e9,1e9,a[i]+k+1,1e9))-1;
        SEG::insert(1,-1e9,1e9,i,a[i]);
        //cout<<st[i][0]<<endl;
    }
    for(int i=n-1;i>=1;i--) {
        if(st[i][0]>st[i+1][0]) st[i][0]=st[i+1][0];
    }
    //for(int i=1;i<=n;i++) cout<<st[i][0]<<" ";
    //cout<<endl;
    for(int t=1;t<=25;t++){
        for(int i=1;i<=n;i++){
            st[i][t]=st[st[i][t-1]+1][t-1];
            //cout<<st[i][t-1]+1<<":";
            //cout<<st[i][t]<<" ";
        }
    //cout<<endl;
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        int ans=0;
        //cout<<l<<endl;
        for(int t=25;t>=0;t--){
            if(st[l][t]!=0&&st[l][t]<=r){
                l=st[l][t]+1;
                //cout<<st[l][t]<<"qwq"<<l<<" "<<t<<endl;
                ans+=(1<<t);
            }
        }
        //cout<<l<<" "<<r<<endl;
        if(l==r) ans++;
        cout<<ans<<endl;
    }
    
}