#include<bits/stdc++.h>
#define N 214514
#define int long long
using namespace std;
int n;
int a[N];
int T;
int kk[3];
char ans[N];
signed main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        kk[0]=kk[1]=kk[2]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]>=2) {
                kk[2]++;
            }
            else {
                kk[a[i]]++;}
        }
        if(kk[0]==1&&kk[1]+kk[2]>0){
            cout<<"NO"<<endl;
            continue;
        }
        if(kk[0]==0){
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++) cout<<"A";
            cout<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        int flag=1;
        
        for(int i=1;i<=n;i++) 
        {
            if(flag&&a[i]==0) {
                cout<<"A";flag=0;}
            else if(a[i]==0) cout<<'B';
            else cout<<'C';
        }
        cout<<endl;
        
    }
}
//cout<<(int)round(onee)-floor(n/4)*floor((n+2)/4)<<endl;