#include<bits/stdc++.h>
#define N 300
using namespace std;
int n;
int ians[N];
bool floy[N][N];
int main()
{
    cin>>n;
    int flag=1;
    for(int i=1;i<=n;i++){
        //floy[i][i]=1;
        cout<<"? ";
        for(int j=1;j<=n;j++){
           if(j!=i) cout<<0;
            else cout<<1;
        }
        cout<<endl;
        cin>>ians[i];
        //if(ans!=1) flag=0;
    }
   
    for(int i=1;i<=n;i++)
    {
        
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++){
                 if(floy[i][j]&&floy[j][k])
                        floy[k][i]=floy[i][k]=1;
            }
        for(int j=i+1;j<=n;j++)
        {
            if(floy[i][j]==0){
cout<<"? ";
            for(int p=1;p<=n;p++)
            {
                if(p!=j&&p!=i) cout<<0;
                else cout<<1;
            }
            cout<<endl;
            int ans;
            cin>>ans;
            if(ans!=ians[i]+ians[j]){
                //cout<<"qwq";
                floy[i][j]=floy[j][i]=1;
            }
            }
            //cout<<i<<" "<<j<<endl;
            
        }
    }
       
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(floy[i][k]&&floy[k][j])
                        floy[j][i]=floy[i][j]=1;
            }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            if(floy[i][j]==0&&floy[j][i]==0) flag=0;
        }
    if(flag) cout<<"! 1"<<endl;
    else cout<<"! 0"<<endl;
}