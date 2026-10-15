#include<bits/stdc++.h>
#define int long long
#define MOD 998244353
using namespace std;
int n;
int a[20];
int ans[20][20];
signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        ans[i][i]=(a[i]+1)%MOD;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(i!=j){
                ans[i][j]=a[j];
            }
        }
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=n;j++){
            printf("%lld ",ans[i][j]);
        }
        printf("\n");
      }
        
        
}
