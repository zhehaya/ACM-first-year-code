#include<bits/stdc++.h>
#define N 214514
#define int long long
using namespace std;
int n;
int h[N];
int s[N];
struct node{
    int son[2];
    int size=0;
    vector<int>val;
}trie[N<<2];
int cnt;
void insert(int id,int value){
    int nowno=0;
    int i=0;
    int nowls=0;
    while(true)
    {
        trie[nowno].size++;
        int ls=trie[nowno].son[0],rs=trie[nowno].son[1];
        if(nowls+trie[ls].size<=id){

        }
        else{

        }
        i++;
    }
    trie[nowno].val.push_back(value);
}
void search(int id){
    int nowno=0;
    for(int i=0;(id>>i)>0;i++)
    {
        //trie[nowno].size++;
        int re=(id>>i)&1;
        //if(trie[nowno].son[re]==0) trie[nowno].son[re]=++cnt;
        nowno=trie[nowno].son[re];
    }
    for(int res:trie[nowno].val){
        cout<<res<<" ";
    }
}
int ans[N];
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&h[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&s[i]);
    sort(h+1,h+1+n);
    sort(s+1,s+1+n);
    for(int i=1;i<=n;i++)
    {
        insert(i-s[i],h[i]);
    }
    for(int i=1;i<=n;i++) search(i);

}