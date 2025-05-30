#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,m,s;cin>>n>>m>>s;

    vector<int> g[n+1];

    for(int i=1;i<n;i++)
    {
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> dep(n+1),size(n+1),fa(n+1),son(n+1);
    function<void(int,int)> dfs1 = [&](int u,int f)
    {
        dep[u] = dep[f] + 1;
        size[u] = 1;
        fa[u] = f;

        for(auto &v:g[u])
        {
            if(v == f)continue;
            dfs1(v,u);
            size[u] += size[v];
            if(son[u]==0||size[v]>size[son[u]])
                son[u] = v;
        }
    };
    vector<int> dfn(n+1),w(n+1),top(n+1);
    int ti = 0;
    function<void(int,int)> dfs2 = [&](int u,int tp)
    {
        dfn[u] = ++ti;
        top[u] = tp;
        if(!son[u])return ;
        dfs2(son[u],tp);

        for(auto & v:g[u])
        {
            if(v == son[u] || v == fa[u])continue;
            dfs2(v,v);
        }
    };
    dfs1(s,0);
    dfs2(s,s);

    auto lca = [&](int u,int v)
    {
        while(top[u]!=top[v])
        {
            if(dep[top[u]] < dep[top[v]])
                swap(u,v);

            u = fa[top[u]];
        }
        return (dep[u]<dep[v])?u:v;
    };

    while(m--)
    {
        int u,v;cin>>u>>v;

        cout<<lca(u,v)<<"\n";
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