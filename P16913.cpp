#include<bits/stdc++.h>
#define int long long
#define N 514514
using namespace std;
const int P=1e9+931;
int T;
int s[N],n;
int has[N],hask[N];//hash[i]10^i%P
void calc_hash()//分段hash
{   
    has[n+1]=0;
    for(int i=n;i>=1;i--)
    {
        has[i]=(has[i+1]*10%P+s[i])%P;
        //cout<<has[i]<<endl;
    }
}
void calc_9()
{
    int nex=0;
    for(int i=1;i<=n+1;i++)
    {
        
        s[i]*=9;
        s[i]+=nex;
        
            nex=s[i]/10;
            s[i]%=10;
        //cout<<s[i]<<endl;
    }
    if(s[n+1]>0) n++;
    //cout<<s[3]<<s[1]<<endl;
}              
int hash_inter(int l,int r)
{
    int res=(has[l]+P-has[r+1]*hask[r-l+1]%P)%P; 
    return res;                                                                                                                                                                                                                                                                                               
}
void solve()
{
    for(int k=n;k>=1;k--)//枚举k
    {
        //cout<<k<<":"<<endl;
        int flag=0;
        int rig=(hask[k]+P-1)%P;
        int lef=0;
        for(int i=1;i<=n;i+=k)//10^k进制下的东西
        {
            if(i+k-1>n){
                lef+=hash_inter(i,n);
            }else{
                lef+=hash_inter(i,i+k-1);
            }//cout<<lef<<endl;
            lef%=P;
        }
        
        for(int t=1;t<=n/k;t++){//枚举t（max为n/k
            if((t*rig)%P==lef){
                flag=1;
                printf("%lld\n",k);
                break;
            }
        }
        if(flag) break;
    }
}                          
signed main()
{
    hask[1]=10;
    for(int i=2;i<=500001;i++){
        hask[i]=hask[i-1]*10%P;
    }
    scanf("%lld",&T);scanf("\n");
    while(T--)
    {
        n=0;
        char c;
        while(scanf("%c", &c) != EOF) {
        if(c=='\n') break;   
        s[++n] = c - '0';
    }
    s[n+1]=0;
        reverse(s+1,s+1+n);
        has[n+1]=0;
        calc_9();
        calc_hash();
        //cout<<hash_inter(2,2)<<endl;
        solve();
    }
    /*
1
11
    */
}