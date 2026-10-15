#include<bits/stdc++.h>
#define N 514514
#define INF 114514191
using namespace std;
struct edge{
    int toid,tow;
};
vector<edge>gra[N];
int T;
int n,m;
int neg[N];//入队次数
int vis[N];//在不在队里
int s[N];
int gg[N],cnt;
void add(int u,int v,int w){
    gra[u].push_back({v,w});
}
bool spfa(){
    queue<int>spfanode;
    spfanode.push(0);
    s[0]=0;
    vis[0]=1;neg[0]=1;
    while(!spfanode.empty()){
        int topnode=spfanode.front();
        spfanode.pop();
        vis[topnode]=0;
        for(auto too:gra[topnode]){
            if(s[topnode]+too.tow<s[too.toid]){
                s[too.toid]=s[topnode]+too.tow;
                if(vis[too.toid]==0){
                    vis[too.toid]=1;
                    neg[too.toid]++;
                    if(neg[too.toid]>n) return 0;
                    spfanode.push(too.toid);
                }
            }
        }
    }
    //if(s[0]!=0) return 0;
    return 1;
}
void solve(){
    cnt=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++){//0<=s_i-s_{i-1}<=1
        gra[i].clear();
        s[i]=INF;
        neg[i]=0;
        vis[i]=0;
        /*
        if(i>=1){
            add(i-1,i,1);
            add(i,i-1,0);
        }*/
    }
    for(int i=1;i<=m;i++){
        int li,ri;
        scanf("%d%d",&ri,&li);//s_li-2>=s_{ri-1}&&s_li<=2+s_{ri-1}
        add(li,ri-1,-2);
        add(ri-1,li,2);
        gg[++cnt]=ri-1;
        gg[++cnt]=li;
    }
    sort(gg+1,gg+1+cnt);
    for(int i=1;i<=cnt;i++){
        add(gg[i-1],gg[i],gg[i]-gg[i-1]);
        add(gg[i],gg[i-1],0);
    }
    
    if(spfa()){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        solve();    
    }
}