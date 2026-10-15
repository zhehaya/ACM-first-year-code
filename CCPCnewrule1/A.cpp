#include<bits/stdc++.h>
#define N 214514
#define INF 11451419198101
#define int long long
using namespace std;
int n;
int L[N],R[N];
int ans[N];
int anssum;
signed main()
{
    scanf("%lld",&n);
    int ini=-INF;
    for(int i=1;i<=n;i++) scanf("%lld%lld",&L[i],&R[i]);
    int beg=n;
    int l=-INF,r=INF;
    for(int i=1;i<=n;i++)
    {
        l=max(l,L[i]);
        r=min(r,R[i]);
        if(l>r) {
            beg=i-1;
            break;
        }
    }
    ini=ans[beg]=l;
    for(int i=beg+1;i<=n;i++)
    {
        if(L[i]>ini){
            ans[i]=L[i];
        }else if(R[i]<ini){
            ans[i]=R[i];
        }else{
            ans[i]=ini;
        }
        ini=ans[i];
    }
    for(int i=1;i<=beg;i++) ans[i]=ans[beg];
    for(int i=2;i<=n;i++)
    {
        anssum+=abs(ans[i]-ans[i-1]);
    }
    printf("%lld\n",anssum);
    for(int i=1;i<=n;i++){
        printf("%lld ",ans[i]);
    }
}