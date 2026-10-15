#include<bits/stdc++.h>
#define N 114514
using namespace std;
int n;
int t[N];
vector<int>val[N];
bool checkhead(int cid,int va){
    int maxx=0,minn=11451411;
    for(int i=cid;i<=cid+2;i++)
    {
        int nowid=(i-1+n)%n+1;
        maxx=max(maxx,t[nowid]);
        minn=min(minn,t[nowid]);
    }
    if(maxx==va||minn==va) return true;
    return false;
}
bool checksingle(int cid,int va){
    for(int i=cid-2;i<=cid;i++)
    {
        int nowid=(i-1+n)%n+1;
        if(checkhead(nowid,va)) return true;
    }
    return false;
}
bool checkze(int cid){
    for(int i=cid-2;i<=cid;i++)
    {
        
        int nowid=(i-1+n)%n+1;
        //cout<<nowid<<endl;
        if(checkhead(nowid,t[cid])) return true;
    }
    return false;
}
bool checkon(int cid){
    for(int i=cid-4;i<=cid+2;i++)
    {
        int nowid=(i-1+n)%n+1;
        
        if(checkhead(nowid,t[cid])) return true;
    }
    return false;
}
int ans[N];
int num[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t[i]);
        val[t[i]].push_back(i);
        num[t[i]]++;
    }
    
    for(int i=1;i<=100005;i++)
    {
       // int need=0;
        int el=n-num[i];
         
        for(int id:val[i]){
            //cout<<id<<endl;
            if(checkze(id)){
               
                ans[i]=el;
                break;//0
            }
            else{
                ans[i]=el+1;
            }
        }
    }
    //cout<<num[4];
    for(int i=1;i<=n;i++) {
        printf("%d ",ans[t[i]]);
    }
        
    //cout<<checkze(1);
}