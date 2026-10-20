#include<bits/stdc++.h>
#define int long long
#define N 214514
using namespace std;
int sumid[N];
int T;
int val;
int hey[N];
int anscnt;
bool solve(int opt,int id){
    anscnt=id;
    int del=sumid[id]-val;
    if(opt==-1) {
        hey[1]=-1;
        del-=2;
    }
    //cout<<del<<"qwq"<<endl;
    //cout<<id<<endl;
    //if(opt==-1) hey[1]=-1;
    //del-=2;
    for(int i=id;del>=0&&i>1;i--){
        //if(del==id+1) break;
        if(del==i*2||del>i*2+2){
            del-=(i*2);hey[i]=-1;
        } 
    }
    if(del==0){
        cout<<anscnt<<endl;
        for(int i=1;i<=anscnt;i++){
        //cout<<"qwq"<<hey[i]<<"qwq";
        int kk=opt*hey[i]*i;
        if(kk<0){
            cout<<"-"<<abs(kk);
        }
        else{
            if(i>1) cout<<"+";
            cout<<abs(kk);
        }
        hey[i]=1;
        }
        cout<<endl;
        return 1;
    }
    for(int i=1;i<=anscnt;i++) hey[i]=1;
    return 0;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=1;i<=200005;i++){
        sumid[i]=sumid[i-1]+i;hey[i]=1;
    }
    cin>>T;
    while(T--)
    {
        cin>>val;
        int flag=1;
        if(val<0) flag=-1;
        val=abs(val);
        int idd=lower_bound(sumid+1,sumid+200002,val)-sumid;
        while(!solve(flag,idd)){
            //cout<<idd<<endl;
            idd++;
        } 
    }
}