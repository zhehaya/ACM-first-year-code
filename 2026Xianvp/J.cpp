#include<bits/stdc++.h>
#define N 514514
using namespace std;
int a[N];
int T;
int n;
int fa[N];
int id[N];
int find(int id)
{
    if(fa[id]!=id) fa[id]=find(fa[id]);
    return fa[id]; 
}
bool merge(int a,int b){
    if(find(a)==find(b)) return 1;
    fa[find(a)]=find(b);
    return 0;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=2*n;i++)
            fa[i]=i,id[i]=0;
        for(int i=1;i<=2*n;i++)
        {
            cin>>a[i]; 
            if(id[a[i]]==0) id[a[i]]=i;
            else {
                merge(id[a[i]],i);
            }
        }
            
        
        stack<int>lsid;
        cout<<"(";lsid.push(1);
        for(int i=2;i<=2*n-1;i++){
            //while(merge(i,i-1))
            //cout<<"ye"<<endl;
            //if(!lsid.empty()) cout<<find(i)<<" "<<find(lsid.top())<<endl;
            if(lsid.empty()||merge(lsid.top(),i)) {
                cout<<"(";lsid.push(i);}
            else {
            cout<<")";lsid.pop();}
        }
        cout<<")";
        cout<<endl;
    }
}