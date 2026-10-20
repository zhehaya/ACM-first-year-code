#include<bits/stdc++.h>
#define int long long
#define N 2145141
using namespace std;
int n,m;
int ans[N];
int a[N];
signed main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=m;i++)
    {
        int bn;
        scanf("%lld",&bn);
        for(int j=1;j<=bn;j++){
            int val;
            scanf("%lld",&val);
            ans[i]+=(n-(lower_bound(a+1,a+1+n,val)-a)+1);
        }
    }
    sort(ans+1,ans+1+m);
    int ini=n*(n+1)/2;
    int rans=0;
    for(int i=1;i<=m;i++){
        ini+=ans[i];
        rans+=ini;
    }
    printf("%lld",rans);
    return 0;
}