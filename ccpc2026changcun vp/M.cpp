#include<bits/stdc++.h>
#define int long long
#define N 1145141
using namespace std;
int num[N];
int n,M;
int a[N];
int ans;
int numm(int val){
    int res=0;
    for(int i=1;i<=val;i++) if(val%i==0) res++;
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=1;i<=1001;i++)
        for(int j=i;i*j<=1000001;j++)
        {
            num[j*i]++;
            if(j!=i) num[j*i]++;
        }
    cin>>n>>M;
    num[0]=M-1;
    for(int i=1;i<=1000001;i++) num[i]--;
       // if(numm(i)!=num[i]) cout<<i<<endl;}
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        //i is mid 
        if(i!=1&&i!=n){
            int maxd=min(n-i,i-1);
            int nowgcd=0;
            for(int d=1;d<=maxd;d++)
            {
                nowgcd=gcd(abs(a[i+d]-a[i-d]),nowgcd);
                ans+=num[nowgcd];
            }
        }
        //i+0.5 is mid
        if(i!=n){
            int maxd=min(n-i,i);
            int nowgcd=0;
            for(int d=1;d<=maxd;d++){
                nowgcd=gcd(abs(a[i+d]-a[i-d+1]),nowgcd);
                ans+=num[nowgcd];
            }
        }
    }
    cout<<ans;
    //for(int i=1;i<=1000;i++) cout<<num[i]<<endl;
}