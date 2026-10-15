#include<bits/stdc++.h>
#define N 3001
#define int long long
using namespace std;
int Z;
int n,m;
int val[N][N];
int dis[N][N][2];
bool vis[N][N];
struct node
{
    int y,x;
};

signed main()
{   
    scanf("%lld",&Z);
    while(Z--)
    {
        scanf("%lld%lld",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                scanf("%lld",&val[i][j]);
                vis[i][j]=0;
                dis[i][j][0]=dis[i][j][1]=-1145141919;
            }
        
        queue<node>spfa;
        vis[1][1]=1;
        dis[1][1][0]=val[1][1];
        spfa.push({1,1});
        while(!spfa.empty())
        {
            node nownode=spfa.front();
            vis[nownode.y][nownode.x]=0;
            //cout<<nownode.x<<" "<<nownode.y<<endl;
            //向左后向下
            spfa.pop();
            //if(nownode.x==n&&nownode.y==m) continue;
            if(nownode.x>1&&nownode.y<n-1){
                if(dis[nownode.y][nownode.x][0]+val[nownode.y+1][nownode.x]+val[nownode.y+1][nownode.x-1]+val[nownode.y+2][nownode.x-1]>dis[nownode.y+2][nownode.x-1][1])
                {
                    dis[nownode.y+2][nownode.x-1][1]=dis[nownode.y][nownode.x][0]+val[nownode.y+1][nownode.x]+val[nownode.y+1][nownode.x-1]+val[nownode.y+2][nownode.x-1];
                    if(!vis[nownode.y+2][nownode.x-1]){
                        spfa.push({nownode.y+2,nownode.x-1});
                        vis[nownode.y+2][nownode.x-1]=1;
                    }
                }
            }
            if(nownode.x<n&&nownode.y<n){
                if(dis[nownode.y][nownode.x][0]+val[nownode.y][nownode.x+1]+val[nownode.y+1][nownode.x]>dis[nownode.y+1][nownode.x][1])
                {
                    dis[nownode.y+1][nownode.x][1]=dis[nownode.y][nownode.x][0]+val[nownode.y][nownode.x+1]+val[nownode.y+1][nownode.x];
                    if(!vis[nownode.y+1][nownode.x]){
                        spfa.push({nownode.y+1,nownode.x});
                        vis[nownode.y+1][nownode.x]=1;
                    }
                }
            }
            /*
            if(nownode.x<n&&nownode.y<n){
                if(dis[nownode.y][nownode.x][0]+val[nownode.y+1][nownode.x]+val[nownode.y+1][nownode.x+1]>dis[nownode.y+1][nownode.x][1])
                {
                    dis[nownode.y+1][nownode.x][1]=dis[nownode.y][nownode.x][0]+val[nownode.y+1][nownode.x]+val[nownode.y+1][nownode.x+1];
                    if(!vis[nownode.y+1][nownode.x]){
                        spfa.push({nownode.y+1,nownode.x});
                        vis[nownode.y+1][nownode.x]=1;
                    }
                }
            }*/
            //向下
            if(nownode.y<n){
                //cout<<"qwq"<<endl;
                if(dis[nownode.y][nownode.x][0]+val[nownode.y+1][nownode.x]>dis[nownode.y+1][nownode.x][0])
                {
                    dis[nownode.y+1][nownode.x][0]=dis[nownode.y][nownode.x][0]+val[nownode.y+1][nownode.x];
                    if(!vis[nownode.y+1][nownode.x]){
                        spfa.push({nownode.y+1,nownode.x});
                        vis[nownode.y+1][nownode.x]=1;
                    }
                }
                if(dis[nownode.y][nownode.x][1]+val[nownode.y+1][nownode.x]>dis[nownode.y+1][nownode.x][1])
                {
                    dis[nownode.y+1][nownode.x][1]=dis[nownode.y][nownode.x][1]+val[nownode.y+1][nownode.x];
                    if(!vis[nownode.y+1][nownode.x]){
                        spfa.push({nownode.y+1,nownode.x});
                        vis[nownode.y+1][nownode.x]=1;
                    }
                }
            }
            //向右
            if(nownode.x<m){
                if(dis[nownode.y][nownode.x][0]+val[nownode.y][nownode.x+1]>dis[nownode.y][nownode.x+1][0])
                {
                    dis[nownode.y][nownode.x+1][0]=dis[nownode.y][nownode.x][0]+val[nownode.y][nownode.x+1];
                    if(!vis[nownode.y][nownode.x+1]){
                        spfa.push({nownode.y,nownode.x+1});
                        vis[nownode.y][nownode.x+1]=1;
                    }
                }
                if(dis[nownode.y][nownode.x][1]+val[nownode.y][nownode.x+1]>dis[nownode.y][nownode.x+1][1])
                {
                    dis[nownode.y][nownode.x+1][1]=dis[nownode.y][nownode.x][1]+val[nownode.y][nownode.x+1];
                    if(!vis[nownode.y][nownode.x+1]){
                        spfa.push({nownode.y,nownode.x+1});
                        vis[nownode.y][nownode.x+1]=1;
                    }
                }
            }
        }
        printf("%lld\n",max(dis[n][m][0],dis[n][m][1]));
    }
    

    
}
