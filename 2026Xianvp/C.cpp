#include<bits/stdc++.h>
#define int __int128
#define INF 114514191981099911111
#define N 3002
int dp[N][N],minval[N][N];
int a[N],b[N];
int T;
int n,m,x,y,z;
int p;
int absl(int vall){
    if(vall<0) return 0-vall;
    return vall;
}
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}
void write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
    return;
}
using namespace std;
signed main()
{
    ios::sync_with_stdio(0);
    
    T=read();
    while(T--){
        n=read(),m=read(),x=read(),y=read(),z=read();
        p=x+z*n;
        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++) dp[i][j]=INF,minval[i][j]=INF;
        for(int i=1;i<=n;i++)
            a[i]=read();
        for(int i=1;i<=m;i++)
            b[i]=read();
        /* for(int i=1;i<=n;i++) 
        {
            dp[1][i]=p+abs(a[i]-b[1]);
        } */
        for(int i=1;i<=m;i++)//匹配b
        {
            for(int j=1;j<=n;j++){//匹配a
                if(i!=1) {
                    dp[i][j]=minval[i-1][j-1]+y*absl(a[j]-b[i]);
                    dp[i][j]=min(dp[i][j],minval[i-1][n]+p+y*absl(a[j]-b[i]));  
                }
                else{
                    dp[1][j]=p+y*absl(a[j]-b[1]);
                    //cout<<dp[1][j]<<" ";
                }
               minval[i][j]=min(minval[i][j-1],dp[i][j]);
                //else minval[i][j]=dp[i][j];
                //cout<<dp[i][j]<<" ";
            } 
            //cout<<endl;
        }
        int ans=dp[m][1];
        for(int i=2;i<=n;i++) 
        {
            ans=min(ans,dp[m][i]);
        }
            
        write(ans-z*m);
        putchar('\n');
    }
}