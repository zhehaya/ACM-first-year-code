#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp1[10][10000],dp2[10][10000];
void inidp1()//dp1[i][j]:i开头j位的总数
{
    for(int i=0;i<=9;i++) dp1[i][1]=1;
    for(int j=2;j<=999;j++)
        for(int i=1;i<=9;i++){
            for(int k=i;k<=9;k++){
                dp1[i][j]+=dp1[k][j-1];
            }
        }
}
void inidp2()//dp2[i][j]:i9999之下的数个数
{
    for(int i=0;i<=9;i++) dp2[i][1]=i+1;
    for(int j=2;j<=999;j++)
        for(int i=0;i<=9;i++){
            if(i==0){
                dp2[i][j]=dp2[9][j-1];
            }
            else{
                dp2[i][j]=dp1[i][j]+dp2[i-1][j];
            }
        }
}
int check(int val)//小于val的数的个数
{
    if(val==0) return 1;
    int res=0;
    int idd=0;
    int wow[23];
    while(val){
        idd++;
        wow[idd]=val%10;
        val/=10;
    }
    int lst=0;
    for(int i=idd;i>=1;i--){
        //cout<<wow[i]<<endl;
        if(wow[i]<lst) break;
        if(i==1){
            res+=(wow[i]-lst+1);
            break;
        }
        res+=(dp2[wow[i]-1][i]);
        if(i!=idd) res-=dp2[lst-1][i];
        //cout<<res<<endl;
        lst=wow[i];
    }
    return res;
}
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}
void write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
    return;
}
int k;
void checck(int val){
    if(val==1) {write(0);return;}
    int lst=0;
    for(int i=500;i>=1;i--){
        for(int j=lst;j<=9;j++){
            if(lst==0)
            {

                if(j>=1&&dp2[j][i]>=val&&dp2[j-1][i]<val) {
                //write(i);puts("");
                write(j);
                val-=(dp2[j-1][i]);//cout<<val;
                lst=j;
                break;} 
                continue;
            }
            if(dp2[j][i]-dp2[lst-1][i]>=val&&dp2[j-1][i]-dp2[lst-1][i]<val) {
                //write(i);puts("qw");
                write(j);
                val-=(dp2[j-1][i]-dp2[lst-1][i]);lst=j;
                break;
                
            } 
        }
       //cout<<"2";
    }
}
signed main(){
    inidp1();inidp2();
    k=read();
    /* while(l<r){
        int mid=(l+r)>>1;
        if(check(mid)<k){
            l=mid+1;
        }else{
            r=mid;
        }
    }  */
    checck(k);
    //puts("");
    //write(l);
}