#include<bits/stdc++.h>

using namespace std;
int n;
int now[26];//当前手上有哪些
int cold[26][2];//当前正在冷却哪些
int ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        int leng=s.length();int id=i%2;
        for(int j=0;j<26;j++) now[j]+=cold[j][id];
        for(int j=0;j<26;j++) cold[j][id]=0;

        for(int j=0;j<leng;j++){
            char st=s[j];
            if(now[st-'A']){
                now[st-'A']--;
                cold[st-'A'][id]++;
            }else{
                ans++;
                cold[st-'A'][id]++;
            }
        }
    }
    cout<<ans;
}