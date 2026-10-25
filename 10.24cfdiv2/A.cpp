#include<bits/stdc++.h>
using namespace std;
int T;
int a[1145];
int n,k;
int is[1145];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=0;i<=101;i++) is[i]=0;
        sort(a+1,a+1+n);
        for(int i=0,j=1;i<=100;i++)
        {
            while(a[j]<=i&&j<=n) j++;
            if(a[j-1]==i&&j-i*k>k){ 
                continue;
            }else{
                cout<<i<<endl;
                break;
            }
        }
    }
    
}