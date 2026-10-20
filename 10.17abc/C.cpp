#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,t;
int a[2145141];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k>>t;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    a[n+1]=t;
    int lst=0,ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]>t) break;
        int ini=a[i];
        //if(lst>=t) break;
        if(lst<ini) ans+=(int)ceil((ini-lst)/(double)(k));
        //cout<<ans<<endl;
        lst=a[i]+k;//cout<<lst<<"qwq"<<endl;
    }
    int ini=t;
    if(lst<ini) ans+=(int)ceil((ini-lst)/(double)(k));
    
    cout<<ans<<endl;
}