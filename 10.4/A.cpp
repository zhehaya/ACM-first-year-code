#include<bits/stdc++.h>
#define N 3001
using namespace std;
int n;
vector<int>tree[N];
int depth[N];
int father[N];
int ans=11451419,ansi;
void dfs(int now,int fa){
    depth[now]=depth[fa]+1;
    for(int v:tree[now]){
        if(v!=fa){
            dfs(v,now);
        }
    }
}
void dfssolve(int now,int fa){
    father[now]=fa;
     int nownode=now;
    while(father[nownode]!=ansi)//jump fa
    {
        printf("%d %d %d\n",father[father[nownode]],father[nownode],nownode);
        father[nownode]=father[father[nownode]];
    }
    for(int v:tree[now]){
        if(v!=fa){
            //cout<<v<<endl;
            dfssolve(v,now);
        }
    }
    //cout<<nownode<<endl;
    
}
int main()
{
     scanf("%d",&n);
     for(int i=1;i<n;i++)
     {
        int u,v;
        scanf("%d%d",&u,&v);
        tree[u].push_back(v);
        tree[v].push_back(u);
     }
     depth[0]=-1;
     for(int i=1;i<=n;i++)//i is root
     {
        dfs(i,0);
        int nowans=0;
        for(int j=1;j<=n;j++){
            if(depth[j]>1) nowans++;
        }
        //nowans-=(n-1);
        if(nowans<=ans){
            ansi=i;
            ans=nowans;
        }
     }
     printf("%d\n",ans);
     //cout<<ansi<<endl;
     dfssolve(ansi,ansi);
}