#include<bits/stdc++.h>
#define int long long
#define N 214514
using namespace std;
int n;
int a[N];
struct node{
    int id,val;
};
node maxx[N],minn[N];
int ma,mi;
int ans=0;
signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
    {
        while(ma!=0&&maxx[ma].val<a[i]) ma--;
        while(mi!=0&&minn[mi].val>a[i]) mi--;
        //a[i]为max 答案，找到第一个大于max头的min
        //cout<<minn[mi].val<<"ha"<<endl;
        int l=1,r=mi;
        while(l<r){
            int mid=(l+r)>>1;
            if(minn[mid].id>=maxx[ma].id){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        //cout<<<<"d"<<endl;r
        if(mi!=0&&minn[r].id>=maxx[ma].id) ans+=(mi-r+1);
        //min
        //cout<<ma<<"ye";
        l=1,r=ma;
        while(l<r){
            int mid=(l+r)>>1;
            if(maxx[mid].id>=minn[mi].id){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        if(ma!=0&&maxx[r].id>=minn[mi].id) ans+=(ma-r+1);
        ans++;
        //cout<<ans<<endl;
        maxx[++ma]={i,a[i]};
        minn[++mi]={i,a[i]};
    }
    printf("%lld",ans);
}