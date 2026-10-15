#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
int n,y;
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
scanf("%lld%lld",&n,&y);
    int maxx=0;
    for(int i=1;i<=n;i++)
    {
        int val;
        scanf("%lld",&val);
        maxx=max(val,maxx);
    }
    int ans=0;
    while(maxx>0)
    {
        maxx-=y;
        maxx++;
        maxx/=2;
        ans++;
    }
    printf("%lld\n",ans);
    }
    
}