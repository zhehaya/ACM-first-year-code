#include<bits/stdc++.h>
using namespace std;
int n;
int k;
int hey[214514];
int dp[214514];
vector<int>tree[214514];
bool check(int nownode){
    //cout<<nownode<<"ba"<<endl;
    return (tree[nownode].size()>=2);
}
void dfs(int nownode,int lstdis,int fa){
   // cout<<nownode<<" "<<lstdis<<endl;
     hey[nownode]=1;
    for(int too:tree[nownode]){
        if(too!=fa){
            dfs(too,lstdis+1,nownode);
            if(dp[too]<k-1){
                dp[nownode]=max(dp[too]+1,dp[nownode]);
                hey[nownode]=1;
                hey[too]=0;
            }
        }
    }
}
int main()
{
    cin>>n>>k;
    for(int i=2;i<=n;i++)
    {
        int val;
        cin>>val;
        tree[min(val,i)].push_back(max(val,i));

    }
    dfs(1,1122,1);
    int ans=0;
    hey[1]=1;
    for(int i=1;i<=n;i++){
        if(hey[i]) ans++;
    }
    cout<<ans<<endl;
   // cout<<dp[6]<<endl;
    for(int i=1;i<=n;i++){
        if(hey[i]) cout<<i<<" ";
    }
}