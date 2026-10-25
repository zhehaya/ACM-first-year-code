#include<bits/stdc++.h>
#define N 314514
#define int long long
using namespace std;
int T;
int n,m,k;
int a[N];
struct node{
    int xi,yi,zi;
}qu[N];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++) a[i]=0;
        for(int i=1;i<=m;i++){
            cin>>qu[i].xi>>qu[i].yi>>qu[i].zi;
            a[qu[i].xi]|=qu[i].zi;
            a[qu[i].yi]|=qu[i].zi;
        }
        int flag=1;
        for(int i=1;i<=m;i++){
            if((a[qu[i].xi]&a[qu[i].yi])!=qu[i].zi) flag=0;
        }
        if(flag==0) cout<<-1<<endl;
        else{
            int ans=0;
            for(int i=1;i<=n;i++) ans+=a[i];
            cout<<ans<<endl;
        }
    }
}