#include<bits/stdc++.h>
#define int long long
using namespace std;
int alcuin(int n) {
    double x=(n%2==0)?(double)n*n
                            :(double)(n+3)*(n+3);
    return (int)floor(x/48.0+0.5);
}
signed main()
{   int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;

        cout<<alcuin(n)<<" "<<endl;
    }
    
} // namespace std;

