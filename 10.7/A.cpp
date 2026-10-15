#include<bits/stdc++.h>
#define N 5145140
using namespace std;
struct node{
    int ch[26];
    int esum=0;
    int id;
}trie[N];
int cnt=0;
int n,q;
string s;
string ans="";
int len;
string hey[50010];
void insert(int nowi,int nownode,int IDD)
{
    //cout<<nownode<<" "<<nowi<<endl;
    if(nowi==len) return;
    int nowch=s[nowi]-'a';
    if(s[nowi]=='y'){
        if(trie[nownode].ch[nowch]==0){
            trie[nownode].ch[nowch]=++cnt;
        }insert(nowi+1,trie[nownode].ch[nowch],IDD);
        s[nowi]='a';
        if(nowi==len-1) {
            trie[trie[nownode].ch[nowch]].esum++;trie[trie[nownode].ch[nowch]].id=IDD;
            
        }
        nowch=0;
        if(trie[nownode].ch[nowch]==0){
            trie[nownode].ch[nowch]=++cnt;
            
        }insert(nowi+1,trie[nownode].ch[nowch],IDD);
        s[nowi]='y';
        if(nowi==len-1) {
            trie[trie[nownode].ch[nowch]].esum++;trie[trie[nownode].ch[nowch]].id=IDD;
            
        }
        return;
    }
    if(s[nowi]=='i'||s[nowi]=='e'||s[nowi]=='o'||s[nowi]=='u'){
            nowch=0;
    }
    if(trie[nownode].ch[nowch]==0){
        trie[nownode].ch[nowch]=++cnt;
    }insert(nowi+1,trie[nownode].ch[nowch],IDD);
    if(nowi==len-1) {
        //cout<<nownode<<endl;
        trie[trie[nownode].ch[nowch]].esum++;
        trie[trie[nownode].ch[nowch]].id=IDD;
    }
}
int ser(string vs)
{
    int leng=vs.length();
    int nowno=0;
    //cout<<trie[0].ch[vs[0]-'a']<<endl;
    for(int i=0;i<leng;i++)
    {
        nowno=trie[nowno].ch[vs[i]-'a'];
        if(nowno==0){
            //cout<<i<<endl;
            return 0;
        }
    }
    //cout<<nowno<<endl;
    ans+=hey[trie[nowno].id];
    //cout<<ans<<endl;
    return trie[nowno].esum;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        len=s.length();
        insert(0,0,i);
        hey[i]=s;
    }
    while(q--)
    {
        int flag=1;
        int m;
        cin>>m;
        ans="";
        for(int i=1;i<=m;i++)
        {
            ans+=" ";
            string qs;
            cin>>qs;
            int kk=ser(qs);
            if(flag==0) continue;
            if(kk==0){
                flag=0;
            }else if(kk>1){
                flag=2;
            }
            
        }
        if(flag==1) cout<<"possible"<<ans<<endl;
        else if(flag==0) cout<<"impossible"<<endl;
        else{
            cout<<"ambiguous"<<endl;
        }

    }
}