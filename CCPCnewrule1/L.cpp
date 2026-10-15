#include<bits/stdc++.h>
#define N 11451
using namespace std;
int n;
int head[N],nex[N];
struct ed{
    int toid,color;
    bool vis=0;
    int id;
}edge[N];
int edcnt=0;
int m;
int zeu;
stack<int>ans;
void add(int u,int v,int c,int IID){
    if(edcnt==0) zeu=u;
    nex[edcnt]=head[u];
    head[u]=edcnt;
    edge[edcnt]={v,c,0,IID};
    ++edcnt;
}
bool cmp(int A,int B){
    return edge[A].color<edge[B].color;
}
bool cmp2(int A,int B){
    return edge[A].color>edge[B].color;
}
void euler(int nownode,int pre){
    int elist[3001];
    int sz=0;
    for(int id=head[nownode];id>=0;id=nex[id])
    {
       
        if(edge[id].vis==0)
        {
           // ed nowe=;
            elist[++sz]=id;
            
            //edge[id].vis=1;
            //edge[id^1].vis=1;
        } //if(id==nex[id]) break;
    }
    
    if(pre==1)sort(elist+1,elist+1+sz,cmp);
    else sort(elist+1,elist+1+sz,cmp2);
    for(int i=1;i<=sz;i++)
    {
        //cout<<edge[elist[i]].id<<" "<<endl;
        if(edge[elist[i]].vis==0)
        {
    edge[elist[i]].vis=1;
        edge[elist[i]^1].vis=1;
        euler(edge[elist[i]].toid,edge[elist[i]].color);
        ans.push(edge[elist[i]].id);
        }
        
    }
    //cout<<endl<<endl;

}
int main()
{
    //int t=3^1;
    //cout<<t<<endl;
   // cout<<"q";
    scanf("%d%d",&n,&m);
    for(int i=0;i<=3*m;i++) head[i]=-1;
    
    for(int i=1;i<=m;i++)
    {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        add(u,v,c,i);
        add(v,u,c,i);
    }
    
    euler(1,1);
    //ans.pop();
    while(!ans.empty()) {
        printf("%d ",ans.top());
        ans.pop();
    }
}