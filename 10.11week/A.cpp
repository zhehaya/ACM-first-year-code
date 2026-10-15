#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
signed main()
{
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int ans=n*(n+1)/2;
        cout<<ans<<endl;
    }
}