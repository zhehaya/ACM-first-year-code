#include<bits/stdc++.h>
using namespace std;
bool check(string a,string b)
{
    int lena=a.length(),lenb=b.length();
    if(lena!=lenb)
        return 0;    
    for(int i=0;i<lena;i++){
        int flag=1;
        for(int j=0;j<lena;j++){
            if(j!=i&&a[j]!=b[j]){
                flag=0;
            }
        }
        if(flag) return 1;
    }return 0;
}
bool check2(string a,string b)
{
    int lena=a.length(),lenb=b.length();
    if(lena!=lenb)
        return 0;    
    for(int i=0;i<lena;i++){
        if(a[i]!=b[i]) return 0;
    }return 1;
}
int n,m;
int ans[102];
string ca[102];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    //cout<<check("baa","bbb")<<endl;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>ca[i];
    }
    for(int i=1;i<=m;i++){
        string ba;
        cin>>ba;
        int flagid=0,flagt=0;
        int ff=0;
        for(int j=1;j<=n;j++)
        {
            if(check2(ba,ca[j])){
                ans[j]++;ff=1;continue;
            }
        }
        if(ff) continue;
        for(int j=1;j<=n;j++)
        {
            if(check(ba,ca[j])){
                flagid=j;
                flagt++;
            }
        }
        if(flagt==1)
            ans[flagid]++;
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
}