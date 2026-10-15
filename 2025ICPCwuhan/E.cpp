#include<bits/stdc++.h>
#define N 514514
using namespace std;
int T;
int n;
int a[N],b[N];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }for(int i=1;i<=n;i++) cin>>b[i];
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        int flaga=0,flagb=0;
        int flags=1;
        int suma=0,sumb=0;
        int jia=a[1]%2,jib=b[1]%2;
        if(a[1]!=b[1]) flags=0;
        suma+=a[1];
        sumb+=b[1];
        for(int i=2;i<=n;i++)
        {
            suma+=a[i];
            sumb+=b[i];
            if(a[i]!=b[i]) flags=0;
            if(abs(a[i]-a[i-1])==1) flaga=1;
            if(abs(b[i]-b[i-1])==1) flagb=1;
            if(a[i]%2) jia++;
            if(b[i]%2) jib++;
        }
        if(flags){
            cout<<"Yes"<<endl;
            //cout<<"kj";
            continue;
        }
        if(jia==jib&&flaga&&flagb&&(abs(suma-sumb)%2==0)){
            cout<<"Yes"<<endl;
        }else cout<<"No"<<endl;
    }
}