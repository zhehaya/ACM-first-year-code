#include<bits/stdc++.h>
#define N 5145141
using namespace std;
int n,a1,a2,a3;
int T;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n>>a1>>a2>>a3;
        if(a1==0&&a2>0&&a3==0){
            cout<<"-1"<<endl;
            continue;
        }
        if(a1==0&&a2==1){
            cout<<7<<" "<<1<<endl;
            cout<<7<<" "<<4<<endl;
            cout<<4<<" "<<2<<endl;
            cout<<2<<" "<<6<<endl;
            cout<<2<<" "<<8<<endl;
            cout<<8<<" "<<3<<endl;
            cout<<8<<" "<<5<<endl;
            bool lst=1;
            for(int i=9;i<=n;i++){
                if(lst) cout<<6<<" "<<i<<endl;
                else cout<<2<<" "<<i<<endl;
                lst=!lst;
            }
            for(int i=1;i<=n;i++) cout<<i<<" ";
            continue;
        }
        if(a1==0&&a3==1){
            cout<<1<<" "<<4<<endl;
            cout<<4<<" "<<2<<endl;
            cout<<5<<" "<<2<<endl;
            cout<<5<<" "<<3<<endl;
            for(int i=6;i<=n;i++){
                cout<<2<<" "<<i<<endl;
            }
            for(int i=1;i<=n;i++) cout<<i<<" ";
            cout<<endl;
            continue;
        }
        if(a1==0)
        {
            if(a2==0)
            {
            cout<<1<<" "<<4<<endl;
            cout<<4<<" "<<7<<endl;
            cout<<1<<" "<<8<<endl;
            cout<<1<<" "<<6<<endl;
            cout<<8<<" "<<5<<endl;
            cout<<8<<" "<<3<<endl;
            cout<<5<<" "<<2<<endl;
            int lst=1;
            for(int i=9;i<=a3+1;i++){
                if(lst) cout<<2<<" "<<i<<endl;
                else{
                    cout<<5<<" "<<i<<endl;
                }
                lst=!lst;
            }
            }else{
                cout<<3<<" "<<1<<endl;
                cout<<2<<" "<<3+a2<<endl;
                cout<<3+a2<<" "<<3<<endl;
                for(int i=4;i<=a2+2;i++){
                    cout<<1<<" "<<i<<endl;
                }
                bool lst=1;
                for(int i=4+a2;i<=n;i++){
                    if(lst) cout<<1<<" "<<i<<endl;
                    else cout<<3<<" "<<i<<endl;
                    lst=!lst;
                }
            }
            
            for(int i=1;i<=n;i++) cout<<i<<" ";
        cout<<endl;
        continue;
        }
        if(a2==0&&a1==1){
            cout<<5<<" "<<2<<endl;
            cout<<1<<" "<<2<<endl;
            cout<<1<<" "<<4<<endl;
            cout<<1<<" "<<6<<endl;
            cout<<3<<" "<<6<<endl;
            bool lst=1;
            for(int i=7;i<=n;i++){
                if(lst) cout<<4<<" "<<i<<endl;
                else cout<<1<<" "<<i<<endl;
                lst=!lst;
             }
             for(int i=1;i<=n;i++) cout<<i<<" ";
        cout<<endl;
            continue;
        }
        for(int i=1;i<a1;i++)
        {
            cout<<i<<" "<<i+1<<endl;
        }
        if(a2==0){
            bool lst=1;
            cout<<a1<<" "<<a1+1<<endl;
            for(int i=a1+2;i<=n;i++){
                if(lst){
                    cout<<a1-1<<" "<<i<<endl;
                }else{
                    cout<<a1<<" "<<i<<endl;
                }
                lst=!lst;
            }
            for(int i=1;i<=n;i++) cout<<i<<" ";
        cout<<endl;
        continue;

        }
        for(int i=a1+1;i<=a1+1+a2;i++){
            cout<<a1<<" "<<i<<endl;
        }
        bool lst=1;
        for(int i=a1+a2+2;i<=a1+a2+a3+1;i++){
            if(lst){
                cout<<a1+1<<" "<<i<<endl;
            }
            else{
                cout<<a1<<" "<<i<<endl;
            }
            lst=!lst;
        }
        for(int i=1;i<=n;i++) cout<<i<<" ";
        cout<<endl;
    }
    
}

