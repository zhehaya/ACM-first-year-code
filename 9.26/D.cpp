#include<bits/stdc++.h>
using namespace std;
int n;
string q;
vector<int>ans;
int main()
{
    cin>>n;
    int nowm=n;
    int ansm,flagans=0;
    for(int i=1;i<=n;i++){
        if(nowm==0) break;
        cout<<"? "<<i<<" "<<nowm<<endl;
        cin>>q;
        if(q=="Yes"){
            int resnowm=nowm;
            while(resnowm>=2){
                cout<<"? "<<i<<" "<<resnowm-1<<endl;
                cin>>q;
                if(q=="No"){
                    break;
                }if(resnowm==2){
                    resnowm--;
                }
                resnowm--;
            }
            if(resnowm==nowm){
                ansm=nowm;
                ans.push_back(i);
                //break;
            }else{
                ans.clear();
                ans.push_back(i);
            }
            nowm=resnowm;
        }
    }
        
    cout<<"! ";
    cout<<ans.size()<<" ";
    for(int id:ans) cout<<id<<" ";
}