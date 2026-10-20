#include<bits/stdc++.h>
#define int long long
using namespace std;
int s[114514];
int sum[114514];
int idsum[114514];
int n,q;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        int val;
        cin>>val;
        sum[i]=sum[i-1]+val;
        idsum[i]=idsum[i-1]+i;
        s[i]=s[i-1]+sum[i];
    }
    for(int i=1;i<=q;i++)
    {
        int l,r;
        cin>>l>>r;
        int lid=lower_bound(idsum+1,idsum+1+n,l)-idsum,rid=lower_bound(idsum+1,idsum+1+n,r)-idsum;
        //cout<<idsum[lid-1]<<" "<<idsum[rid-1]<<endl;
       // cout<<rid<<endl;
        int ans=s[rid]-s[lid];//cout<<ans<<endl;
        ans+=(sum[lid]-sum[l-idsum[lid-1]-1]);//cout<<ans<<endl;
        ans-=(sum[rid]-sum[r-idsum[rid-1]]);
        cout<<ans<<endl;
    }
    
}