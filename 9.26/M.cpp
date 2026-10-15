#include<bits/stdc++.h>
using namespace std;
int n;
string kong(int x)
{
    string res="";
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=x;j++)
            res+=".";
        res+="\n";
    }
    return res;
}
string add(string A,string B){
    string res="";
    for(int i=0,j=0;i<A.size();i++){
        if(A[i]=='\n'){
            while(B[j]!='\n'){
                //cout<<j<<endl;
                res+=B[j];
                j++;
            }
            j++;
        }
        res+=A[i];
        //cout<<i<<" "<<j<<endl;
    }
    
    return res;
}
int main()
{
    scanf("%d",&n);
    string ans="*\n";
    for(int i=1;i<=n;i++)
    {
        int k=pow(3,i-1);
        //cout<<k<<endl;
        //cout<<kong(k);
        string anst=add(ans,add(kong(k),ans));
        anst+=add(kong(k),add(ans,kong(k)));
        anst+=add(ans,add(kong(k),ans));
        
        ans=anst;
    }
    cout<<ans;
}