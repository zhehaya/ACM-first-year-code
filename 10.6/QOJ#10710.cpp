#include<bits/stdc++.h>
#define N 114514
#define int long long
using namespace std;
namespace SEG{
    int a[N];
    struct node{
        int minval;
        int insum;
        int lazytag=0;
    }segtree[N<<2];
    void push_up(int nownode)
    {
        int ls=nownode<<1,rs=nownode<<1+1;
        segtree[nownode].insum=segtree[ls].insum+segtree[rs].insum;
        segtree[nownode].minval=min(segtree[ls].minval,segtree[rs].minval);

    }
    void push_down(int nownode)//push下去的一定可行，所以不会造成子结构错误，第二个pushdown函数负责子结构错误的暴力修改
    {
        if(segtree[nownode].)
    }
    void updown_index(int nownode){//暴力修改，但是势能上正确
        if()
    }
    void build(int nownode,int l,int r){
        if(l==r){
            
        }        
    }
    void update(){

    }
    void update_single(){

    }
    bool isyes(){

    }
}
int main()
{

}
//明天再来探索吧