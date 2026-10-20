#include<bits/stdc++.h>
using namespace std;
string s;
int len;
int main()
{
    cin>>s;
    len =s.length();
    string ans="";
    char lst='&';
    for(int i=1;i<len;i++)
    {
        ans+=s[i];
        if(s[i]!=s[i-1])
            ans+=s[i-1];
       
    }

    cout<<ans;

}