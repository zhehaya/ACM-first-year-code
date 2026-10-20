#include<bits/stdc++.h>
#define int long long
#define INF 11451419198101
using namespace std;
int T;
int n,m,s;
signed main()
{
    scanf("%lld",&T);
    //cout<<ceil(1.10)<<endl;
    while(T--)
    {
        scanf("%lld%lld%lld",&n,&m,&s);
        int le=sqrt(s);
        int ans=INF;
        for(int i=1;i<=le;i++)
        {
            int re=s/i;
            
            ans=min(ans,max((int)ceil(n/(double)i)-1,0ll)+max((int)ceil(m/(double)re)-1,0ll));
            ans=min(ans,max((int)ceil(n/(double)re)-1,0ll)+max((int)ceil(m/(double)i)-1,0ll));
        }
        printf("%lld\n",ans);
    }
}