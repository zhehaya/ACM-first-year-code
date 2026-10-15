#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int n;
signed main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        if(n==1) {
            cout<<"NO"<<endl;continue;}
        int sz=sqrt(n);
        int flag=1;
        for(int i=2;i<=sz;i++)
        {
            if(n%i==0) flag=0;
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}