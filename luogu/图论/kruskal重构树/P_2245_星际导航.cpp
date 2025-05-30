#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
struct DSU
{
    vector<int> fa;

    DSU(int n):fa(n+1){iota(fa.begin(),fa.end(),0);}

    int find(int x)
    {
        if(fa[x]!=x)
            fa[x] = find(fa[x]);
        return fa[x];
    }

    bool merge(int x,int y)
    {
        int fx = find(x),fy = find(y);
        if(fx == fy)
            return false;

        fa[fx] = fy;
        return true;
    }
    bool same(int x,int y)
    {
        return find(x) == find(y);
    }
};
struct Edge
{
    int u,v,w;
    bool operator<(Edge t) const
    {
        return w<t.w;
    }
};

void work()
{
    int n,m;cin>>n>>m;

    vector<Edge> e(m+1);

    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        e[i] = {u,v,w};
    }

    sort(++e.begin(),e.end());
    vector<int> g[2*n+1];
    DSU dsu(2*n);
    vector<int> a(2*n+1);
    int idx = n;
    for(int i=1;i<=m;i++)
    {
        auto [u,v,w] = e[i];
        if(dsu.same(u,v))continue;
        int fu = dsu.find(u),fv = dsu.find(v);
        g[++idx].push_back(fu);
        g[fu].push_back(idx);
        g[fv].push_back(idx);
        g[idx].push_back(fv);
        a[idx] = w;
        dsu.fa[fu] = idx;
        dsu.fa[fv] = idx;
    }

    vector<int> son(2*n+1),top(2*n+1),fa(2*n+1),dep(2*n+1),size(2*n+1);

    function<void(int,int)> dfs1 = [&](int u,int ls)
    {
        fa[u] = ls;
        dep[u] = dep[ls] + 1;
        size[u] = 1;
        for(auto &v:g[u])
        {
            if(v == ls)continue;
            dfs1(v,u);
            size[u] += size[v];
            if(size[v]>size[son[u]])
                son[u] = v;
        }
    };

    function<void(int,int)> dfs2 = [&](int u,int tp)
    {
        top[u] = tp;
        if(!son[u]) return;
        dfs2(son[u],tp);

        for(auto &v:g[u])
        {
            if(v==fa[u]||v==son[u])continue;
            dfs2(v,v);
        }
    };
    for(int i=1;i<=idx;i++)
    {
        int fa = dsu.find(i);
        if(!son[fa])
        {
            dfs1(fa,0);
            dfs2(fa,fa);
        }
    }

    auto lca =[&](int u,int v)
    {
        while(top[u]!=top[v])
        {
            if(dep[top[u]]<dep[top[v]])swap(u,v);
            u = fa[top[u]];
        }
        return dep[u]<dep[v]?u:v;
    };
    int q;cin>>q;
    while(q--)
    {
        int u,v;cin>>u>>v;
        if(dsu.same(u,v))
        {
            int l = lca(u,v);
            cout<<a[l]<<"\n";
        }
        else
            cout<<"impossible"<<"\n";

    }
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