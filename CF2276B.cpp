#include<bits/stdc++.h>
using namespace std;
signed main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        int a=1,b=0,c=0;
        for(int i=1;i<s.length()-1;i++){
            if(s[i]!=s[i-1]&&s[i+1]!=s[i]){
                c=1;
            }if(s[i]==s[i-1]&&s[i+1]==s[i]){
                b=1;
            }
        }
        cout<<a+b+c<<endl;
    }
}