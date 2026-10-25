#include<bits/stdc++.h>
#define N 114514
#define int long long
using namespace std;
int n,k;
int sum[N];
int a[N];
map<int,int>sumod;
int ans=0;
signed main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    sumod[0]=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
        ans+=sumod[sum[i]%k];
        sumod[sum[i]%k]++;
    }
    cout<<ans;
        
}