#include<bits/stdc++.h>
#define int __int128
using namespace std;
int n;
int a[214514];
int sum[214514],sumi[214514];
int check(int val){
    int res=0;
    res+=sum[n]-sum[val];
    res-=val*(sumi[n]-sumi[val]);
    res+=val*sumi[val-1];
    res-=sum[val-1];
    /*
    for(int i=1;i<=n;i++){
        res+=a[i]*abs(i-val);
    }
    */
    return res;
}
int ansid,ans;
inline void print(int n){
    if(n<0){
        putchar('-');
        n*=-1;
    }
    if(n>9) print(n/10);
    putchar(n % 10 + '0');
}
inline void read(int &n){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    n=x*f;
}
signed main()
{
    ios::sync_with_stdio(0);
    read(n);
    for(int i=1;i<=n;i++){
    read(a[i]);
    sum[i]=sum[i-1]+a[i]*i;sumi[i]=sumi[i-1]+a[i];
    }
    ansid=1;
    ans=check(1);
    for(int i=2;i<=n;i++){
        //cout<<i<<" "<<check(i)<<endl;
        if(check(i)<ans) ansid=i,ans=check(i);
    }
    print(ansid);putchar(' ');
    //cout<<" ";
    print(ans);
}