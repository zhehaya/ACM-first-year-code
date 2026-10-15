#include<bits/stdc++.h>
#define int long long 
#define N 114514
#define double long double
using namespace std;
const int INF=1e9+1;
struct node{
    int sum=0;
    int ls,rs;
}seg[1114514];
int segcnt=1;
int n,x;
double eps=0.00000000001;
struct worm{
    int li,ri,vi;
}sand[N];
bool cmp(worm A,worm B){
    return A.ri-A.li<B.ri-B.li;
}
int newnode(int val){
    segcnt++;
    int resid=segcnt;
    seg[resid]={val,0,0};
    return resid;
}
int floo(double X){
    int resx=X;
    if(X!=(double)resx) resx++;
    return resx;
}
void push_up(int id){
    seg[id].sum=seg[seg[id].ls].sum+seg[seg[id].rs].sum;
}
bool update(int id,int l,int r,int L,int R){//将[L,R]赋值为1，并判断是否有必要的赋值
    seg[0].sum=0;
   // cout<<l<<"q"<<r<<"w"/*<<seg[2].sum*/<<endl;
    if(l==r){
        //cout<<"done";
        if(seg[id].sum==0){
            seg[id].sum=1;//cout<<1<<endl;
            return 1;
        }
        //cout<<0<<endl;
        return 0;
    }
    if(l>=L&&r<=R){
        //cout<<"done";
        if(seg[id].sum<(r-l+1)){
            seg[id].sum=(r-l+1);//cout<<seg[id].sum<<endl;
            return 1;
        }
        //cout<<0<<endl;
        return 0;
    }
    
    int mid=(l+r)>>1;
    int resflag=(seg[id].sum==(r-l+1));
    if(resflag) return 0;
    //cout<<seg[id].sum<<"yeye"<<resflag<<endl;
    bool res=0;
    if(mid>=L){
        if(!seg[id].ls) 
            seg[id].ls=newnode(resflag*(mid-l+1));
        if(resflag)seg[seg[id].ls].sum=resflag*(mid-l+1);
        res|=update(seg[id].ls,l,mid,L,R);
    }
    if(mid<R){
        if(!seg[id].rs) 
            seg[id].rs=newnode(resflag*(r-mid));
        if(resflag)seg[seg[id].rs].sum=resflag*(r-mid);
        res|=update(seg[id].rs,mid+1,r,L,R);
    }
    push_up(id);
    return res;
}
int ans=0;
double li[N*20];
int licnt;
signed main()
{
    scanf("%lld%lld",&n,&x);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld%lld",&sand[i].li,&sand[i].ri,&sand[i].vi);
    sort(sand+1,sand+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        double LL=(double)(x-sand[i].ri)/((double)sand[i].vi),RR=(double)(x-sand[i].li)/((double)sand[i].vi);
        li[++licnt]=LL;
        li[++licnt]=RR;
        li[++licnt]=LL+eps;
        li[++licnt]=RR+eps;
        li[++licnt]=LL-eps;
        li[++licnt]=RR-eps;
    }
    li[++licnt]=0.00;
    sort(li+1,li+1+licnt);
    licnt=unique(li+1,li+1+licnt)-(li+1);
        int kk=licnt;
    for(int i=2;i<=kk;i++){
        li[++licnt]=(li[i]+li[i-1])/2.0;
    }
    sort(li+1,li+1+licnt);
   // for(int i=1;i<=licnt;i++) cout<<li[i]<<" ";
    //cout<<endl;
    for(int i=1;i<=n;i++)
    {
        double LL=(double)(x-sand[i].ri)/((double)sand[i].vi),RR=(double)(x-sand[i].li)/((double)sand[i].vi);
        int Lid=lower_bound(li+1,li+1+licnt,LL)-li;
        int Rid=lower_bound(li+1,li+1+licnt,RR)-li;
        
        //cout<<li[Lid]<<" "<<li[Rid]<<endl;
        if(li[Rid]<0.000) continue;
        if(li[Lid]<0.000){
            Lid=lower_bound(li+1,li+1+licnt,0.00)-li;
        }
        //Lid=max(0ll,Lid);
        if(Rid>=Lid){
           // cout<<i<<" "<<Lid<<" "<<Rid<<endl;
            bool flag=update(1,1,licnt,Lid,Rid);
            //cout<<flag<<endl;
            if(flag) ans=sand[i].ri-sand[i].li;
            //cout<<i<<endl;
        }
    }
    printf("%lld",ans);
}