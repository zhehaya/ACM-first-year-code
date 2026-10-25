#include<bits/stdc++.h>
#define int long long
#define N 1145141
using namespace std;
int n,q;
int que[N];
struct node{
	int val,size,pri;
	int ls,rs;
}tree[N<<1];
int cnt,root;
int newnode(int date)
{
	++cnt;
	tree[cnt]={date,1,rand(),0,0};
	return cnt;
}
void push_up(int now)
{
	tree[now].size=tree[tree[now].ls].size+tree[tree[now].rs].size+1;
}
void spilt(int now,int x,int &L,int &R)
{
	if(now==0){
		L=R=0;return;
	}
	if(tree[now].val<=x){
		L=now;
		spilt(tree[now].rs,x,tree[now].rs,R);
	}
	else{
		R=now;
		spilt(tree[now].ls,x,L,tree[now].ls);
	}
	push_up(now);
}
int merge(int L,int R)
{
	if(L==0||R==0) return L+R;
	if(tree[L].pri>tree[R].pri)
	{
		tree[L].rs=merge(tree[L].rs,R);
		push_up(L);
		return L;
	}else{
		tree[R].ls=merge(L,tree[R].ls);
		push_up(R);
		return R;
	}
}
int serchk(int now,int k)//求第k大数
{
	if(tree[tree[now].ls].size+1==k) return tree[now].val;
	if(tree[tree[now].ls].size>=k) return serchk(tree[now].ls,k);
	else	return serchk(tree[now].rs,k-tree[tree[now].ls].size-1);
}
void insert(int date)
{
	int id=newnode(date);
	int L,R;
	spilt(root,date,L,R);
	root=merge(merge(L,id),R);
}
void del(int date)
{
	int L,p,R;
	spilt(root,date,L,R);
	spilt(L,date-1,L,p);
	p=merge(tree[p].ls,tree[p].rs);
	root=merge(merge(L,p),R);
}

int rankk(int date)
{
	int L,R;
	spilt(root,date-1,L,R);
	int re=tree[L].size+1;
	root=merge(L,R);
	return re;
}
int pre(int date)//找到前趋
{
	int L,R;
	spilt(root,date-1,L,R);
	int re=serchk(L,tree[L].size);
	root=merge(L,R);
	return re;
}
int nxt(int date)
{
	int L,R;
	spilt(root,date,L,R);
	int re=serchk(R,1);
	root=merge(L,R);
	return re;
}
int wow(int val){
    return val*(val+1)/2;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    srand(time(0));
    cin>>n>>q;
    insert(0);
    insert(n+1);
    int ans=wow(n);
    //cout<<ans<<endl;
    for(int i=1;i<=q;i++){
        cin>>que[i];
        int pree=pre(que[i]),nxtt=nxt(que[i]);
        ans+=wow(que[i]-pree-1);
        ans+=wow(nxtt-que[i]-1);
        ans-=wow(nxtt-pree-1);
        cout<<ans<<endl;
        insert(que[i]);
        //cout<<wow(qu[i]-1)+wow(n-qu[i])<<endl;
    }


}