#include<bits/stdc++.h>
#define int long long
#define N 214514
using namespace std;
int T;
int n;
struct node{
    int x,y;
    bool operator<(const node& B)const{
        return x<B.x;
    }
}mul[N];

bool check(int val)
{
    if(val==mul[n].x) return true;
    int nowt=1;//目前剩余所有值至少需要达到的数量
    int res=0;//结余给0的数
    int lst=val-1;//上一个有数的上一个
    for(int i=n;i>=0;i--)
    {
       // cout<<i<<":"<<endl;
        if(nowt>2e14){
            return false;
        }
        if(lst!=mul[i].x){
            int k=lst-mul[i].x;
            for(int i=1;i<=k;i++){
                nowt*=2;
                if(nowt>2e14)
                    return false;
            }
           // cout<<nowt<<endl;
        }
        if(mul[i].y>nowt){
            res+=(mul[i].y-nowt);
            if(mul[i].x==0) return true;
        }
        else{
            int del=nowt-mul[i].y;
            nowt+=del;
            if(mul[i].x==0){
                if(res>=del) return true;
                else{
                    return false;
                }
            }
        }
        lst=mul[i].x-1;
    }
    
}
void solve()
{
    int l=mul[n].x,r=2e14;
   // cout<<check(1145)<<endl;
    while(l<r){
        //cout<<l<<" "<<r<<endl;
        int mid=(l+r+1)>>1;
        if(check(mid)){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    printf("%lld\n",l);
}
signed main()
{

    scanf("%lld",&T);
    while(T--)
    {
       scanf("%lld",&n);
       for(int i=1;i<=n;i++)
            scanf("%lld%lld",&mul[i].x,&mul[i].y);
        sort(mul+1,mul+1+n);
        //cout<<mul[n].x;         
       // check(4);
        //cout<<endl<<endl<<endl; 
        solve() ;
    }
}
/*
1
1
1 2
*/