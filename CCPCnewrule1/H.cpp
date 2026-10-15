#include<bits/stdc++.h>
#define N 501
using namespace std;
int n;
int u,maxi,v;
int udis[N];
int vdis[N];
int zhi[N],cnt;
int lian[N],lcnt=0;
bool cmp(int A,int B){
    return udis[A]<udis[B];
}
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        cout<<"? "<<1<<" "<<i<<endl;
        int res;
        cin>>res;
        if(res>maxi) {u=i;maxi=res;}
    }
    for(int i=1;i<=n;i++)
    {
        if(i!=u){
            cout<<"? "<<u<<" "<<i<<endl;
            cin>>udis[i];
            if(udis[i]>=udis[v])
                v=i;
        }
    }
    int len=udis[v];
    for(int i=1;i<=n;i++){
        if(i!=v){
            cout<<"? "<<v<<" "<<i<<endl;
            cin>>vdis[i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(udis[i]+vdis[i]==len){
            zhi[++cnt]=i;
        }
    }
    sort(zhi+1,zhi+1+cnt,cmp);
    cout<<"!\n";
    for(int i=2;i<=cnt;i++){
        //cout<<udis[zhi[i-1]]<<endl;
        cout<<zhi[i-1]<<" "<<zhi[i]<<endl;
    }
    for(int i=1;i<=n;i++){
        int flag=1;
        for(int j=1;j<=cnt;j++) if(zhi[j]==i) flag=0;
        if(flag){
            lian[++lcnt]=i;
        }
    }
    sort(lian+1,lian+1+lcnt,cmp);
    int beg=0;
    for(int i=1;i<=cnt;i++){
        if(udis[zhi[i]]<udis[lian[1]]){
            beg=zhi[i];
        }
    }
    //cout<<udis[1]<<endl;
    //cout<<u<<"qwq"<<v<<endl;
    if(lcnt>0)
    {
        cout<<beg<<" "<<lian[1]<<endl;
        for(int i=2;i<=lcnt;i++){
        cout<<lian[i-1]<<" "<<lian[i]<<endl;
    }}
}