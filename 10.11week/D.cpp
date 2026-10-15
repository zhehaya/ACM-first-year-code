#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int solve(int x)
{
    int rr=0;
    while(x%10==0)
    {
        rr++;
        x/=10;
    }
    return rr;
}
signed main()
{
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int t=2,f=5;
        int ts=0,fs=0;
        while(t<=n)
        {
            ts+=n/t;
            t*=2;
        }
        while(f<=n)
        {
            fs+=n/f;
            f*=5;
        }
        cout<<min(ts,fs)<<endl;
    }
}