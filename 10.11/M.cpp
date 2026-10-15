#include<bits/stdc++.h>
#define N 214514
#define int long long
using namespace std;
int n;
int l[N];
int sl[N];
signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&l[i]);sl[i]=sl[i-1]+l[i];}
    int ans;
    for(int i=1;i<=n;i++){
        int flag=1;
        for(int j=2;j*sl[i]<=sl[n];j++){
            int id=lower_bound(sl+1,sl+1+n,j*sl[i])-sl;
            if(sl[id]!=j*sl[i]){
                flag=0;break;
            }
        }
        if(flag){
            ans=sl[i];
            break;
        }
    }
    printf("%lld",ans);

}