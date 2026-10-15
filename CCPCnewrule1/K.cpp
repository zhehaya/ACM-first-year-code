#include<bits/stdc++.h>
#define int long long
#define N 801
#define INF 114514191981011
using namespace std;
int n;
int fa[N];
int fadis[N];
struct edge{
    int toi,dis;
};
struct node{
    int A,B,R;
}nodeval[N];
vector<edge>tree[N];

void dfs(int node,int father)
{
    for(edge toid:tree[node]){
        if(toid.toi!=father){
            fa[toid.toi]=node;
            fadis[toid.toi]=toid.dis;
            dfs(toid.toi,node);
        }
    }
}
int Q;
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        tree[u].push_back({v,w});
        tree[v].push_back({u,w});
    }
    dfs(1,1);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld%lld",&nodeval[i].A,&nodeval[i].B,&nodeval[i].R);
    }
    scanf("%lld",&Q);
    fa[1]=0;
    while(Q--){
        int vi,qi;
        scanf("%lld%lld",&vi,&qi);
        int nowu=vi;
        int ans=INF;
        int nowdis=0;
        while(nowu!=0){
            
            int nowres=nodeval[nowu].A*qi+nodeval[nowu].B+nowdis;
           //cout<<"qwq"<<nowres<<endl;
            if(nowdis<=nodeval[nowu].R) ans=min(ans,nowres);
            nowdis+=fadis[nowu];
            nowu=fa[nowu];
            
        }
        printf("%lld\n",ans);
    }

}