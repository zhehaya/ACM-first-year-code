#include<bits/stdc++.h>
#define N 401
#define int long long
#define INF 11451419198101
using namespace std;
int n,m,k;
int dis[N<<1][N<<1];
struct edge{
    int u,v,val;
    bool operator<(edge B){
        return val<B.val;
    }
}ed[214514];
int cnte;
int vert[N<<1],cntvt;
int ver[N<<1],cntv;
int rm;//需要考虑的边
int ans[214514],cntans;
signed main()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    
    for(int i=1;i<=m;i++)
    {   cnte++;
        scanf("%lld%lld%lld",&ed[cnte].u,&ed[cnte].v,&ed[cnte].val);
    }
    sort(ed+1,ed+1+m);
    rm=min(400ll,m);
    for(int i=1;i<=rm;i++)
    {
        vert[++cntvt]=ed[i].u;
        vert[++cntvt]=ed[i].v;
    }
    sort(vert+1,vert+1+cntvt);
    for(int i=1;i<=cntvt;i++)
    {
        if(vert[i]!=vert[i-1]){
            cntv++;
            ver[cntv]=vert[i];
           // cout<<cntv<<":"<<vert[i]<<endl;
        }
    }
    for(int i=1;i<=cntv;i++)
        for(int j=1;j<=cntv;j++) dis[i][j]=INF;
    
    for(int i=1;i<=rm;i++)
    {
        int uid=lower_bound(ver+1,ver+1+cntv,ed[i].u)-ver;
        int vid=lower_bound(ver+1,ver+1+cntv,ed[i].v)-ver;
        dis[uid][vid]=ed[i].val;
        dis[vid][uid]=ed[i].val;
    }
    /*

                 for(int k = 1; k <= cntv; k ++)
		for(int i = 1; i <= cntv; i ++)
			for(int j = 1; j <= cntv; j ++)
			if(dis[i][j] > dis[i][k] + dis[k][j])
				dis[i][j] = dis[i][k] + dis[k][j];
                */
       for(int i=1;i<=cntv;i++)
       {
for(int j=1;j<i;j++)
            for(int k=1;k<i;k++)
            {
                dis[j][i]=min(dis[j][k]+dis[k][i],dis[j][i]);
                dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
            
            }
            for(int j=1;j<i;j++)
            for(int k=1;k<i;k++)
            {
   
                dis[k][j]=min(dis[k][i]+dis[i][j],dis[j][k]);
                dis[j][k]=min(dis[j][i]+dis[i][k],dis[k][j]);
            }
       }
        
           // cout<<"qwqq";
    for(int i=1;i<=cntv;i++)
        for(int j=i+1;j<=cntv;j++)
        {
            ans[++cntans]=dis[i][j];
        }
    sort(ans+1,ans+cntans+1);
    printf("%lld",ans[k]);
    
}
/*
2 1 1
1 2 1
*/