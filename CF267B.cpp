#include<bits/stdc++.h>
#define N 10
using namespace std;
struct edge{
    int id;
    char dir;
    int tonode;
};
vector<edge>g[N];
int used[114];
edge ans[114];
int cnt;
void euler(int nownode){
    for(auto v:g[nownode]){
        if(!used[v.id]){
            used[v.id]=1;
            euler(v.tonode);
            ans[++cnt]=v;
        }
        
    }
    
}
int n;
int dep[114];
void putsans(){
        if(cnt==n){
            for(int i=1;i<=cnt;i++){
                printf("%d %c\n",ans[i].id,ans[i].dir);
            }
        }else{
            puts("No solution");
        }
    
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int le,ri;
        scanf("%d%d",&le,&ri);
        g[le].push_back({i,'-',ri});
        g[ri].push_back({i,'+',le});
        dep[le]++;
        dep[ri]++;
    }
    int od=0,be;
    for(int i=0;i<=6;i++){
        if(dep[i]%2) {
            od++;
            be=i;
        }
    }
    if(od==0){
        for(int i=0;i<=6;i++){
            if(dep[i]>0){
                euler(i);
                break;
            }
        }
        putsans();
    }else if(od==2){
        euler(be);
        putsans();
    }
    else{
        puts("No solution");
    }
}