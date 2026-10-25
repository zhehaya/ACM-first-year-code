#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n=114;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(gcd(i,j)==1&&gcd(i,j+1)!=1) cout<<i<<" "<<j<<endl;
        }
    return 0;
}
