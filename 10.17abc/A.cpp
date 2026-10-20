#include<bits/stdc++.h>
using namespace std;
signed main()
{
    string s,t;
    cin>>s;
    cin>>t;
    if(s[0]=='A'&&t[1]=='D'){cout<<"No";
        return 0;
    } 
    if(s[0]=='D'&&t[1]=='A') {cout<<"No";
        return 0;
    } 
    if(s[1]=='D'&&t[0]=='A'){cout<<"No";
        return 0;
    } 
    if(s[1]=='A'&&t[0]=='D') {cout<<"No";
        return 0;
    } 
    cout<<"Yes";
    return 0;

}