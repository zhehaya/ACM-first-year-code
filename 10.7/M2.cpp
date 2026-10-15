#include<bits/stdc++.h>
#define N 214514
#define int long long
using namespace std;
int n;
int h[N];
int s[N];
int ans[N];
namespace SEG{
    int tree[N<<2];
    void push_up(int node){
        tree[node]=tree[node<<1]+tree[(node<<1)+1];
    }
    void insert(int val,int nownode,int id,int l,int r)
    {   //cout<<l<<"q"<<r<<"k"<<nownode<<endl;
        if(l==r){//cout<<SEG::tree[4]<<endl;
            //cout<<nownode<<endl;
            tree[nownode]--;
            ans[l]=val;
            
            return;
        }
        
        int ls=nownode<<1,rs=(nownode<<1)+1;
        //cout<<ls<<" "<<rs<<endl;
        int mid=(l+r)>>1;
        if(tree[ls]<id){
            //cout<<ls<<endl;
            insert(val,rs,id-tree[ls],mid+1,r);
        }else{
            insert(val,ls,id,l,mid);
            
        }
        //cout<<SEG::tree[4]<<endl;
        push_up(nownode);
    }
    void build(int nownode,int l,int r)
    {
        if(l==r){
            tree[nownode]=1;return;
        }
        int ls=nownode<<1,rs=(nownode<<1)+1;
        int mid=(l+r)>>1;
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(nownode);
    }
}

signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&h[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&s[i]);
    sort(h+1,h+1+n);
    sort(s+1,s+1+n);
    SEG::build(1,1,n);
    for(int i=n;i>=1;i--)
    {
        //cout<<i-s[i]<<" "<<h[i]<<endl<<endl;
        //cout<<SEG::tree[4]<<endl;
        SEG::insert(h[i],1,i-s[i],1,n);
    }
    int flag=1;
    for(int i=1;i<=n;i++){
        if(ans[i]==0) flag=0;
    }
    if(flag)    for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
    else printf("-1");

}