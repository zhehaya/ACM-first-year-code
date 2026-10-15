#include<bits/stdc++.h>
#define int long long
#define N 214514
#define P 998244353
using namespace std;
int n,m;
int a[N],b[N];
int two_pow[N];
int two_sum[N];
int ans=0;
signed main()
{
    two_pow[0]=1;two_sum[0]=1;
    for(int i=1;i<=200005;i++) {
        two_pow[i]=two_pow[i-1]*2;
        two_pow[i]%=P;
        two_sum[i]=(two_sum[i-1]+two_pow[i])%P;
    }
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        a[i]+=(i-1)*20;
    }
        
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&b[i]);
        b[i]+=(i-1)*20;
    }
    //int res=0;
    reverse(b+1,b+1+m);
    //for(int i=1;i<=m;i++) cout<<b[i]<<endl;
    
    for(int i=1;i<=n;i++)
    {
        int l=0,r=m;
        //最后一个b>=a的位置
        while(l<r)
        {
            int mid=(l+r+1)>>1;
            if(b[mid]>=a[i]){
                l=mid;
            }else{
                r=mid-1;
            }
        }
        
        int nowres=(1+two_sum[l-1])%P;
        //cout<<nowres<<endl;
        nowres*=two_pow[n-i];
        nowres%=P;
        ans+=nowres;
        ans%=P;
        
    }
    
    printf("%lld",ans);

}