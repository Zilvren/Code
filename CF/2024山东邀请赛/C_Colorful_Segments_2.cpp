#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 5e5+7;
const int p = 998244353;
mt19937 sj(114514);//随机数
struct FHQ {
    int l, r;
    int key, val;
    int sz;
} fhq[N];

int root, T1, T2, T3, idx;

int build(int v) {
    fhq[++idx] = {0,0,(int)sj(),v,1};
    return idx;
}

void push_up(int u) {
    fhq[u].sz = fhq[fhq[u].l].sz + fhq[fhq[u].r].sz + 1;
}
//分裂
//val  分裂成两棵树， 第一颗树 <= v,第二棵树 > v
void split(int u, int v, int &x, int &y) {
    if(!u) {
        x = y = 0;
        return;
    }
    if(fhq[u].val <= v) {
        x = u;
        split(fhq[u].r,v,fhq[u].r,y);
    }
    else {
        y = u;
        split(fhq[u].l,v,x,fhq[u].l);
    }
    push_up(u);
}

//合并
//key， 小根堆，根节点要小于左右子树的key
int merge(int x, int y) {
    if(!x||!y) return x+y;
    if(fhq[x].key < fhq[y].key) {
        fhq[x].r = merge(fhq[x].r, y);
        push_up(x);
        return x;
    }
    else {
        fhq[y].l = merge(x, fhq[y].l);
        push_up(y);
        return y;
    }
}

void insert(int v) {
    split(root,v,T1, T2);
    //T1 <= v  T2 > v
    root=merge(merge(T1, build(v)),T2);
}

void erase(int v) {
    split(root,v,T1,T2);
    //T1 <= v  T2 > v
    split(T1,v-1,T1,T3);
    //T1 < v  ,T3 == v,T2 > v
    T3 = merge(fhq[T3].l,fhq[T3].r);
    root = merge(merge(T1,T3),T2);
}
//查找排名为k的元素值
int kth(int k) {
    int u = root;
    while(u) {
        int rk = fhq[fhq[u].l].sz + 1;
        if(rk == k)break;
        else if(rk > k) {
            u = fhq[u].l;
        }
        else {
            k -= rk;
            u = fhq[u].r;
        }
    }
    return fhq[u].val;
}
//查找元素v的排名
int rk(int v) {
    split(root,v-1,T1,T2);
    int res = fhq[T1].sz + 1;
    root = merge(T1, T2);
    return res;
}

//查找元素v的前驱 小于v 中的最大值
int find_pre(int v) {
    split(root,v-1,T1,T2);
    int u = T1;
    while(fhq[u].r) {
        u = fhq[u].r;
    }
    root = merge(T1, T2);
    return fhq[u].val;
}

//查找元素v的后继 大于v 中的最小值
int find_suf(int v) {
    split(root, v,T1,T2);
    int u = T2;
    while(fhq[u].l) {
        u = fhq[u].l;
    }
    root = merge(T1, T2);
    return fhq[u].val;
}
void work()
{
    root = T1 = T2 = T3 = idx = 0;
    int n,k;cin>>n>>k;
    vector<array<int,2>> a(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }

    sort(++a.begin(),a.end());


    int ans=1;
    for(int i=1;i<=n;i++)
    {
        split(root,a[i][0]-1,T1,T2);
        int sz = fhq[T2].sz;
        ans *= (k%p - sz%p + p)%p;
        ans %=p;
        root = merge(T1,T2);
        if(k - sz<=0)
        {
            cout<<0<<"\n";
            return ;
        }
        insert(a[i][1]);
    }
    cout<<ans<<"\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t=1;
    cin>>t;
    while(t--)
        work();
}