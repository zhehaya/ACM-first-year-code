#include<bits/stdc++.h>
#define N 3003
#define int long long
using namespace std;
int Z;
int n,m;
int val[N][N];
int dp[N][N][2][3];

signed main()
{   
    scanf("%lld",&Z);
    while(Z--)
    {

        scanf("%lld%lld",&n,&m);
        for(int i=0;i<=n+1;i++)
            for(int j=0;j<=m+1;j++) {
                dp[i][j][0][1]=dp[i][j][0][0]=-1145141919;
                dp[i][j][1][1]=dp[i][j][1][0]=-1145141919;
                dp[i][j][1][2]=dp[i][j][0][2]=-1145141919;
                val[i][j]=-1145141;}
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%lld",&val[i][j]); 
       
        //cout<<val[2][2]<<endl;
        dp[1][1][0][1]=val[1][1];
        dp[1][1][0][0]=val[1][1];
       for(int i=1;i<=n;i++)
       {
        for(int j=1;j<=m;j++)
        {

                dp[i][j][0][1]=max(dp[i][j][0][1],max(dp[i][j-1][0][0],dp[i][j-1][0][1])+val[i][j]);
                dp[i][j][0][0]=max(dp[i][j][0][0],max(dp[i-1][j][0][0],dp[i-1][j][0][1])+val[i][j]);
                //cout<<dp[i][j][0][0]<<" ";
        }
        //cout<<endl;
       }
       /*
       for(int i=1;i<=n;i++)
       {
        for(int j=1;j<=m;j++)
        {

                dp[i][j][0][1]=max(dp[i][j][0][1],max(dp[i][j-1][0][0],dp[i][j-1][0][1])+val[i][j]);
                dp[i][j][0][0]=max(dp[i][j][0][0],max(dp[i-1][j][0][0],dp[i-1][j][0][1])+val[i][j]);
                cout<<dp[i][j][0][0]<<" ";
        }
        cout<<endl;
       }
*/

            for(int i=1;i<=n;i++)
       {
        for(int j=1;j<=m;j++)
        {
                dp[i][j][1][1]=max({dp[i][j][1][1],max(dp[i][j-1][1][0],dp[i][j-1][1][1])+val[i][j],dp[i][j-1][1][2]});
                dp[i][j][1][0]=max({dp[i][j][1][0],dp[i-1][j][1][0],dp[i-1][j][1][1],dp[i-1][j][1][2]})+val[i][j];
                dp[i][j][1][2]=max({dp[i][j][1][2],dp[i][j+1][0][0]+val[i][j],dp[i][j+1][0][1]});    
            //cout<<dp[i][j][1][1]<<" ";
        }
        //cout<<endl;
       }
    
    printf("%lld\n",max({dp[n][m][1][0],dp[n][m][1][1],dp[n][m][0][0],dp[n][m][0][1]}));
    }

    
}
