#include<bits/stdc++.h>
#define N 2145141
using namespace std;
int n;
int cnt[N];
int p[N];
struct BIT{
   int bit[N];//树状数组本体
   int nid;//树状数组大小
   int lowbit(int x) {return x&(-x);}
   void update(int id,int date)//单点加
   {
        for(int i=id;i<=nid;i+=lowbit(i)) bit[i]+=date;
   }
   int query(int id)//查询前缀和
   {
        int res=0;
        for(int i=id;i>0;i-=lowbit(i)) res+=bit[i];
        return res;
   }
}val;
int ans[N];
int idp[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;val.nid=2*n;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        idp[p[i]]=i;
        val.update(i,1);
        val.update(i+n,1);
    }
    int head=1;
    for(int i=n;i>=1;i--){
        int id=idp[i];
        int end=head+n-1;
        if(id<head) id+=n;
        ans[i]=val.query(end)-val.query(id-1);
        head=idp[i];
        val.update(idp[i],-1);
        val.update(idp[i]+n,-1);
        
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    

}