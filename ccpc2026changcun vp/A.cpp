#include<bits/stdc++.h>
#define N 1145141
#define int long long
using namespace std;
int n,m;
vector<int>al[N];
int nowr[N];
int ans=0;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int a;
            cin>>a;
            al[j].push_back(a);
        }

    for(int i=1;i<=m;i++){
        for(int j=0;j<n;j++){
            if(al[i][j]>=nowr[j]){
                ans+=(al[i][j]-nowr[j]);
                nowr[j]=al[i][j];
            }else{
                nowr[j+1]+=(nowr[j]-al[i][j]);
                nowr[j]=al[i][j];
            }
        }
    }
    cout<<ans;
    
}