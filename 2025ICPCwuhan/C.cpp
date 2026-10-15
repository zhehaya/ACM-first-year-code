#include<bits/stdc++.h>
using namespace std;
int n,m;
int T;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        if(min(n,m)==1&&max(n,m)>=9){
            printf("No\n");
            continue;
        }printf("Yes\n");
        int flag=0;
        if(m%3!=0) {
            swap(n,m);
            flag=1;
        }
        int ans[n+1][m+1];
        
        //goto A;
        
        //int odd=n%2;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                ans[i][j]=0;
            }
        for(int i=1;i<=n;i++)
        {
            
                switch(i%4)
                {
                    case 0:{
                        for(int j=2;j<=m;j+=3)
                            ans[i][j]=1;
                        break;
                    }
                    case 1:{
                        for(int j=1;j<=m;j+=3)
                            ans[i][j]=1;
                        break;
                    }
                    case 2:{
                        for(int j=2;j<=m;j+=3)
                            ans[i][j]=1;
                        break;
                    }
                    case 3:{
                        for(int j=3;j<=m;j+=3)
                            ans[i][j]=1;
                        break;
                    }
                }
            
        }
        if(n==1){
             for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                ans[i][j]=0;
            }
            for(int i=1;i<=n*m/3;i++) ans[1][i]=1;
        }
        int sz=n*m/3;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                if(ans[j][i]==0&&sz>0){
                    sz--;ans[j][i]=2;
                }
            }
            if(!flag)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++) printf("%d",ans[i][j]);
                printf("\n");
            }
            
        }
        
        else{
            for(int i=1;i<=m;i++)
            {
                for(int j=1;j<=n;j++) printf("%d",ans[j][i]);
                printf("\n");
            }
                
        }
    }
}