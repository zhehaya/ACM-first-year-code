#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    for(int n=1;n<=50;n++){
        cout<<pow(pow(2ll,n)-1,20ll)/pow(pow(2ll,n),20ll)<<endl;
    }
}