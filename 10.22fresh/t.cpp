#include<bits/stdc++.h>
#define N 114514
using namespace std;


string id[11]={" _ \n| |\n|_|\n","   \n  |\n  |\n"," _ \n _|\n|_ \n _ \n _|\n|_ \n"," _ \n _|\n _|\n _ \n _|\n _|\n","   \n|_|\n  |\n"," _ \n|_ \n _|\n"," _ \n|_ \n|_|\n"," _ \n  |\n  |\n"," _ \n|_|\n|_|\n"," _ \n|_|\n _|\n"};
struct num{
    int realval;
    string val;
    
};
int main()
{
    for(int i=1;i<=3;i++){
        string kk;
        getline(cin,kk);
        for(int j=0,t=1;j<18;j+=3,t++){
            aa[2]+=kk[j];
            aa[2]+=kk[j+1];
            aa[2]+=kk[j+2];
            aa[2]+="\\n";
        }
    }
}