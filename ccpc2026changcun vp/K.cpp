#include<bits/stdc++.h>
#define N 5145141
#define INF 114514191
#define int long long
using namespace std;
int n,m,q;
namespace SEG1{//for pre
    struct node{int val,lazytag=0;
    }tree[N<<2];
    int cnt;
    void push_up(int nowid){
        tree[nowid].val=max(tree[nowid<<1].val,tree[(nowid<<1)+1].val);
        return;
    }
    void maketag(int nowid,int date){
        tree[nowid].lazytag=date;
        tree[nowid].val=date;return;
    }
    void push_down(int nowid){
        if(tree[nowid].lazytag){
            maketag(nowid<<1,tree[nowid].lazytag);
            maketag((nowid<<1)+1,tree[nowid].lazytag);
            tree[nowid].lazytag=0;
        }
        return;
    }
    void build(int nowid,int l,int r){
        if(l==r){
            tree[nowid].val=INF;
            return;
        }
        int mid=(l+r)>>1;
        build(nowid<<1,l,mid);
        build((nowid<<1)+1,mid+1,r);
        push_up(nowid);
    }
    void update(int nowid,int l,int r,int L,int R,int date){
        if(l>=L&&r<=R){
            maketag(nowid,date);
            return;
        }
        push_down(nowid);
        int mid=(l+r)>>1;
        if(L<=mid) update(nowid<<1,l,mid,L,R,date); 
        if(R>mid)   update((nowid<<1)+1,mid+1,r,L,R,date);
        push_up(nowid);return;
    }
    int query(int nowid,int l,int r,int L,int R){
        if(l>=L&&r<=R){
            return tree[nowid].val;
        }
        int res=0,mid=(l+r)>>1;
        push_down(nowid);
        if(L<=mid) res=max(res,query(nowid<<1,l,mid,L,R));
        if(R>mid) res=max(res,query((nowid<<1)+1,mid+1,r,L,R));
        push_up(nowid);return res;
    }
}
namespace SEG2{//求和
    struct node{int val;
    }tree[N<<2];
    int cnt;
    void push_up(int nowid){
        tree[nowid].val=tree[nowid<<1].val+tree[(nowid<<1)+1].val;
        return;
    }
    void build(int nowid,int l,int r){
        if(l==r){
            tree[nowid].val=1;
            return;
        }
        int mid=(l+r)>>1;
        build(nowid<<1,l,mid);
        build((nowid<<1)+1,mid+1,r);
        push_up(nowid);
    }
    void update(int nowid,int l,int r,int ID){
        if(l==r){
            tree[nowid].val=0;
            return;
        }
        int mid=(l+r)>>1;
        if(ID<=mid) update(nowid<<1,l,mid,ID); 
        else  update((nowid<<1)+1,mid+1,r,ID);
        push_up(nowid);return;
    }
    int query(int nowid,int l,int r,int L,int R){
        if(l>=L&&r<=R){
            return tree[nowid].val;
        }
        int res=0,mid=(l+r)>>1;
        if(L<=mid) res+=query(nowid<<1,l,mid,L,R);
        if(R>mid) res+=query((nowid<<1)+1,mid+1,r,L,R);
        push_up(nowid);return res;
    }

}
struct con{
    int opt;
    int xi;
}col[N];
int xid[N<<2],cnt;
int fu[N];
vector<int>funode[N];
struct qunode{
    int lid,id;
};
vector<qunode>ques[N];
int ans[N];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++){
        cin>>col[i].opt>>col[i].xi;
        xid[++cnt]=col[i].xi;
        if(col[i].xi>1)xid[++cnt]=col[i].xi-1;
        if(col[i].xi<n)xid[++cnt]=col[i].xi+1;
    }
    sort(xid+1,xid+1+cnt);
    n=unique(xid+1,xid+1+cnt)-(xid+1);
    SEG1::build(1,1,n);
    for(int i=m;i>=1;i--){
        int realx=lower_bound(xid+1,xid+1+n,col[i].xi)-xid;
        if(col[i].opt==0)
        {
            fu[i]=SEG1::query(1,1,n,1,realx);
            SEG1::update(1,1,n,1,realx,i);
        }
        else{
            fu[i]=SEG1::query(1,1,n,realx,n);
            SEG1::update(1,1,n,realx,n,i);
        }
    }
    //for(int i=1;i<=m;i++)cout<<fu[i]<<" ";
    for(int i=1;i<=m;i++){
        if(fu[i]<INF) funode[fu[i]].push_back(i);
    } 
    for(int i=1;i<=q;i++){
        int li,ri;
        cin>>li>>ri;
        ques[ri].push_back({li,i});
    }
    SEG2::build(1,1,m);
    for(int i=1;i<=m;i++){//解决ri为i的疑问
        for(int upd:funode[i])//将funode[i]的所有i都-1
            SEG2::update(1,1,m,upd);
        for(auto pro:ques[i])//li到ri求和
        {
            ans[pro.id]=SEG2::query(1,1,m,pro.lid,i);
        }
    }
    for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
}