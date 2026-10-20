#include<bits/stdc++.h>
#define N 2145141
using namespace std;
int T;
string s;
int icpc[N][4],cnt[4];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    int cntc;
    while(T--)
    {
        cin>>s;
        cnt[0]=cnt[1]=cnt[2]=cnt[3]=0;
        int len=s.length();
        cntc++;
        for(int i=0;i<=len;i++){
            icpc[i][0]=icpc[i][1]=icpc[i][2]=icpc[i][3]=0;
        }
        //reverse(s,s+len);
        for(int i=len-1;i>=0;i--){
            //cout<<s[i]<<endl;
            if(s[i]=='C'){
                if(cnt[1]<cnt[2]){
                    cnt[1]++;
                    icpc[cnt[1]][1]=i+1;
                }else{
                    cnt[3]++;
                    icpc[cnt[3]][3]=i+1;
                }
            }
            else if(s[i]=='P'){
                if(cnt[2]<cnt[3])
                {
                    cnt[2]++;
                    icpc[cnt[2]][2]=i+1;
                }
                
            }
            else if(s[i]=='I'){
                if(cnt[0]<cnt[1]){
                //if(i==1) cout<<cnt[0]<<"qwq"<<cnt[2]<<endl;
                cnt[0]++;
                icpc[cnt[0]][0]=i+1;}
            }
        }
        int ans=min({cnt[0],cnt[1],cnt[2],cnt[3]});
        //cout<<cnt[2]<<cnt[3]<<endl;
        cout<<ans<<endl;
        for(int i=1;i<=ans;i++){
            for(int j=0;j<=3;j++) cout<<icpc[i][j]<<" ";
            cout<<endl;
        }

    }
    
}