#include<bits/stdc++.h>
#define N 1145141
using namespace std;
string s[5];
int ans[5];
int note[5];
int T;
int flag[5];
int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){//cout<<T;
        //cout<<"qwq"<<endl;
        cin>>n;
        for(int i=1;i<=4;i++) {cin>>s[i];ans[i]=2000;note[i]=0;flag[i]=1;}
        for(int i=0;i<n;i++){
            for(int j=1;j<=4;j++)
            {
                switch(s[j][i]){
                    case 'H':{
                        note[j]++;
                        break;
                    }
                    case 'J':{
                        note[j]=0;
                        ans[j]-=50;
                        break;
                    }
                    case 'A':{
                        note[j]=0;
                        ans[j]-=100;
                        break;
                    }
                    case 'M':{
                        note[j]=0;
                        ans[j]-=200;
                        break;
                    }
                    default:{
                        note[j]=0;
                        break;
                    }
                }if(note[j]==100){
                    //cout<<"ye";
                    note[j]=0;
                    for(int k=1;k<=4;k++) if(k!=j) ans[k]+=30;
                }
            }
            for(int j=1;j<=4;j++){
                
                if(ans[j]>=2000) ans[j]=2000;
                if(ans[j]<=0) flag[j]=0;
                ans[j]=flag[j]*ans[j]; 
            }
            
        }
    for(int i=1;i<=4;i++) cout<<ans[i]<<" ";
    cout<<endl;

    }

}