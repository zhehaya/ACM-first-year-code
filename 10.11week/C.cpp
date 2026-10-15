#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int a,b,c;
int rounds(int a, int b, int c){
    int v[3]= {a,b,c};
    sort(v, v + 3);         
    return min(v[1]-v[0],v[2]-v[1]);
}
signed main()
{
    cin>>T;
    while(T--)
    {
        cin>>a>>b>>c;
        if(a==b||b==c||c==a) {
            cout<<0<<endl;
            continue;
        }
        cout<<rounds(a,b,c)<<endl;
    }
}
