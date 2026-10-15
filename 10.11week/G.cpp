#include<bits/stdc++.h>
using namespace std;
int alcuin(int n) {
    double x=(n%2==0)?(double)n*n
                            :(double)(n+3)*(n+3);
    return (int)floor(x/48.0+0.5);
}
int main()
{
    for(int n=1;n<=40;n++)
    {int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
            for(int k=1;k<j;k++){
                if(i+j+k==n&&(i+j+k-max({i,j,k})>max({i,j,k}))){
                    ans++;//cout<<i<<" "<<j<<" "<<k<<endl;
            }}
        cout<<ans<<" "<<endl;
    }
    //pow(n,3)/((1-pow(n,2))*(1-pow(n,3))*(1-pow(x,4))).
    //x^3/((1-x^2)*(1-x^3)*(1-x^4)).
}