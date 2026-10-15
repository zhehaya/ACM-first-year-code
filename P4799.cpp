#include<bits/stdc++.h>
#define int long long
using namespace std;
struct state{
    int isr=0;
    int coinval=0;
}dp1[1<<20],dp2[1<<20];
int coincnt[1<<20];//dp2
int coin[41];
int n;
int m;
int ans=0;
int licoin[1<<20],licnt;
int licoinf[1<<20],cnt;
signed main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%lld",&coin[i]);
    int up=n/2;

    int down=n-up;
    int upsz=(1<<up)-1,downsz=(1<<down)-1;
    dp1[0]={1,0};
    for(int i=1;i<=downsz;i++)
    {
        int low=i&(-i);
        int id=__builtin_ctz(low);
        int prev=i^low;
        dp2[i].coinval=dp2[prev].coinval+coin[up+id];
        if(dp2[i].coinval<=m) {
            dp2[i].isr=1;
            licoin[++licnt]=dp2[i].coinval;
        }
    }
    sort(licoin+1,licoin+1+licnt);
    int lst=0;
    licoinf[0]=1;
    for(int i=1;i<=licnt;i++){
        if(licoin[i]!=licoin[i+1]) {
            //cout<<licoin[i]<<endl;
            licoin[++cnt]=licoin[i];
            licoinf[cnt]=i-lst+licoinf[cnt-1];
            //cout<<licoin[cnt]<<" "<<licoinf[cnt]<<endl;
            lst=i;
        }
    }
    //for(int i=1;i<=cnt;i++)
    for(int i=1;i<=upsz;i++)
    {
        int low=i&(-i);
        int id=__builtin_ctz(low);
        int prev=i^low;
        dp1[i].coinval=dp1[prev].coinval+coin[id];
        //cout<<id<<" "<<i<<" "<<dp1[i].coinval<<endl;
        if(dp1[i].coinval<=m) {
            dp1[i].isr=1;
            int nos=upper_bound(licoin+1,licoin+1+cnt,m-dp1[i].coinval)-licoin-1;
            //cout<<licoin
            ans+=licoinf[nos];
            //cout<<m-dp1[i].coinval<<"q"<<nos<<endl;
            //licoin[++licnt]=m-dp1[i].coinval;
        }
    }
    int nos=upper_bound(licoin+1,licoin+1+cnt,m)-licoin-1;
            //cout<<licoin
    //cout<<nos<<endl;
    ans+=licoinf[nos];
    printf("%lld",ans);
}