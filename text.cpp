#include<bits/stdc++.h>
using namespace std;
int n=2,k=2;
int main()
{
    int ans=0;
    for(int i=1;i<=(1<<(n))-1;i++){
    int noww=i;
    int gcd=0;
    int ji=1;
    for(int j=1;j<=(n);j++){
        if((noww>>(j-1))&1) {gcd=__gcd(gcd,j),ji*=j;}
    }
    cout<<ji<<" "<<gcd<<endl;
    if((ji/gcd)%k==0) ans++; 
}
    cout<<ans;
    
}