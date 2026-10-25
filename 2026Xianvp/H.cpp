#include<bits/stdc++.h>
#define int long long
#define N 114514
using namespace std;
const int INF=1e9;
struct stk{
    int ai,bi;
}hate[N];
struct AS{
    int id,a,d;
}asval[N];
int ascnt;
int T;
int n,x,y;
bool cmp(stk A,stk B){
    return A.ai<B.ai;
}
bool cmp2(AS A,AS B){
    return A.id<B.id;
}
void solve()
{
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++){
        cin>>hate[i].ai>>hate[i].bi;
    }
    ascnt=0;
    sort(hate+1,hate+1+n,cmp);
    int preid=INF,prea=0;
    for(int i=1;i<=n;i++){
        int outt=hate[i].ai-hate[i-1].ai;
        if(prea+(INF-preid)<=outt) preid=INF,prea=0;
        else if(preid==1&&prea>outt){
            prea-=outt;
        }
        else{
            preid=outt-prea+preid;
            prea=0;
        }
        if(preid>hate[i].bi){
            asval[++ascnt]={hate[i].bi,0,-1};
            asval[++ascnt]={preid,prea,1};
            preid=hate[i].bi;
            prea=0;
        }
    }
    sort(asval+1,asval+1+ascnt,cmp2);
    for(int i=1;i<=ascnt;i++){

    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--)
    {
       solve();
    }
}