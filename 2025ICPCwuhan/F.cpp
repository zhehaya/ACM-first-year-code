#include<bits/stdc++.h>
#define N 1145141
int T;
int n,q;
using namespace std;
struct index{
    int L,R;
    bool operator<(const index& B)const{
        return R<B.R;
    }
}qlist[N];
int sz;
int dp[N];
int treecalc(int val){
    if(dp[val]) return dp[val];
    if(val==0) return 0;
    if(val==1) return 1;
    int mid=(val+1)/2;
    dp[val]=1+treecalc(max(mid-1,val-mid));
    return dp[val];
}   
signed main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&q);
        for(int i=1;i<=q;i++)
            scanf("%d%d",&qlist[i].L,&qlist[i].R);
        sort(qlist+1,qlist+1+q);
        int lst=0;sz=0;
        for(int i=1;i<=q;i++){
            if(qlist[i].L>lst){
                //cout<<lst<<endl;
                lst=qlist[i].R;
                sz++;
            }
        }
        //cout<<sz<<" ";
        //cout<<treecalc(2);
        printf("%d\n",treecalc(sz));
        
    }
    

}