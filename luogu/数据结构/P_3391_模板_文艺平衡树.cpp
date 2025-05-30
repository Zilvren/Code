#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
mt19937 rd(1);

struct FHQ
{
    int l,r;
    int val,key;
    int sz;
    int tag;
}tr[N];
int root,T1,T2,T3,idx;
int build(int x)
{
    tr[++idx] = {0,0,x,rd(),1};
    return idx;
}
void push_up(int u)
{
    tr[u].sz = tr[tr[u].l].sz + tr[tr[u].r].sz + 1;
}
void push_down(int u)
{
    if(tr[u].tag)
    {
        swap(tr[u].l,tr[u].r);
        tr[tr[u].l].tag^=1;
        tr[tr[u].r].tag^=1;
    }
    tr[u].tag = 0;
}
void split(int u,int k,int &x,int &y)
{
    if(!u)
    {
        x = y = 0;
        return ;
    }
    push_down(u);
    if(tr[tr[u].l].sz + 1<=k)
    {
        x = u;
        k-=tr[tr[u].l].sz+1;
        split(tr[u].r,k,tr[u].r,y);
    }
    else
    {
        y = u;
        split(tr[u].l,k,x,tr[u].l);
    }
    push_up(u);
}
int merge(int x,int y)
{
    if(!x||!y)
        return x+y;
    
    if(tr[x].key<tr[y].key)
    {
        push_down(x);
        tr[x].r = merge(tr[x].r,y);
        push_up(x);
        return x;
    }
    else
    {
        push_down(y);
        tr[y].l = merge(x,tr[y].l);
        push_up(y);
        return y;
    }
}
void insert(int x)
{
    root = merge(root,build(x));
}
void print(int u)
{
    push_down(u);
    if(tr[u].l)
        print(tr[u].l);
    cout<<tr[u].val<<" ";
    if(tr[u].r)
        print(tr[u].r);
}
void reverse(int l,int r)
{
    split(root,r,T1,T3);
    split(T1,l-1,T1,T2);
    tr[T2].tag^=1;
    root = merge(merge(T1,T2),T3);
}
void work()
{
    int n,m;cin>>n>>m;

    for(int i=1;i<=n;i++)
        insert(i);

    for(int i=1;i<=m;i++)
    {
        int l,r;cin>>l>>r;
        reverse(l,r);
    }

    print(root);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    // int t=1;
    // cin>>t;
    // while(t--)
        work();
}