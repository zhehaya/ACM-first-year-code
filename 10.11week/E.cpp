#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,y;
int sz(int val){
    int res=0;
    while(val>0){
        res++;
        val/=10;
    }return res;
}
signed main()
{
cin>>T;
while(T--)
{
    cin>>y;
    int l=sz(y);
    cout<<1;
    for(int i=1;i<l;i++){
        cout<<0;
    }cout<<1<<endl;
}
}