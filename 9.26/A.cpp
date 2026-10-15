#include<bits/stdc++.h>
#define N 214514
#define int long long
int T;
int n;
int x[N];
int xval[N];
void solve(){
    int nowsum=0,flag=1;
    for(int i=1;i<=n;i++)
    {
        if(x[i]==-1){
            xval[i]=nowsum+1;
        }else{
            if(x[i]<=nowsum) flag=0;
            xval[i]=x[i];
        }
        nowsum+=(xval[i]);
    }
    if(flag){
        printf("No");
    }else{
        printf("Yes");
    }
}
signed main(){
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&x[i]);
        }
    }
}