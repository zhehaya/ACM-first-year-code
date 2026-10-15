#include<bits/stdc++.h>
#define N 310
#define int long long
using namespace std;
const int P=1e9;
int F[N][N];
string S="&";
int solve(int l,int r)//解决子树的子问题
{if(S[l]!=S[r]) return 0;
    if(F[l][r]>0) return F[l][r];
    
    if(r==l){
        F[l][r]=1;
        return F[l][r];
    }
    F[l][r]+=solve(l+1,r-1);
    for(int i=l+2;i<=r-2;i++){
        if(S[i]==S[l]){
            F[l][r]+=((solve(l+1,i-1)*solve(i,r))%P);
            F[l][r]%=P;
        }
    }
    return F[l][r];
}
signed main()
{
    string inn;
    cin>>inn;
    S+=inn;
    int len=inn.length();
    cout<<solve(1,len);
}