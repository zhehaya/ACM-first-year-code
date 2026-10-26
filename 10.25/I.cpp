#include<bits/stdc++.h>
#define int long long
#define N 114514
using namespace std;
int T;
int jie[N];
int smallC[3][3] = {
    {1, 0, 0},
    {1, 1, 0},
    {1, 2, 1}
};

int C(long long n, long long m) {
    if(n<3&&m<3) return smallC[n][m];
    if(m==0) return 1;
    return C(n/3,m/3)*C(n%3,m%3);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //jie[0]=1;
    //for(int i=1;i<=10000;i++) jie[i]=(jie[i-1]*i)%3;
    cin>>T;
    //cout<<C(4,2);
      while(T--)
    {
        int n;
        cin>>n;
        int ans=0;
        
        for(int i=1;i<=n;i++)
        {
            int kk=min(i-1,n-i);
            int val;
            cin>>val;
            val%=3;
            //cout<<n-1<<" "<<i<<" "<<kk<<"qwq"<<endl;
            ans+=(C(n-1,kk)*val)%3;
            //cout<<ans<<endl;
            ans%=3;
        }
        if((n-1)%2==1) ans=0-ans;
        ans+=3;
        ans%=3;
        cout<<ans<<endl;
    }  
}