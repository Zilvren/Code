#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
struct DSU
{
    vector<int> fa,w;
    DSU(int n,vector<int> w):fa(n+1),w(w){iota(fa.begin(),fa.end(),0);}

    int find(int x)
    {
        if(fa[x] != x)
            fa[x] = find(fa[x]);

        return fa[x];
    }
    int merge(int x,int y)
    {
        int fx = find(x),fy = find(y);
        if(fx == fy)
            return false;
        w[fy] = min(w[fx],w[fy]);
        fa[fx] = fy;
        return true;
    }
};
void work()
{
    int n;cin>>n;
    vector<int> x(n+1);
    vector<int> c(n+1);
    vector<array<int,2>> g[n+1];
    for(int i=1;i<=n;i++)
        cin>>x[i];

    for(int i=1;i<=n;i++)
        cin>>c[i];
    vector<int> in(n+1);
    for(int i=1;i<=n;i++)
    {
        g[i].push_back({x[i],c[i]});
        in[x[i]] ++;
    }
    DSU dsu(n,c);
    vector<bool> vis(n+1);
    int ans = 0;
    auto topu = [&]()
    {
        queue<int> Q;
        for(int i=1;i<=n;i++)
        {
            if(in[i] == 0)
                Q.push(i),vis[i] = 1;;
        }
        while(Q.size())
        {
            int u = Q.front();
            Q.pop();

            for(auto &[v,w]:g[u])
            {
                in[v] -- ;
                if(in[v] == 0)
                {
                    vis[v] = 1;
                    Q.push(v);
                }
            }
        }
    };
    topu();
    int root = 0;
    function<void(int)> dfs = [&](int u)
    {
        vis[u] = 1;
        for(auto &[v,w]:g[u])
        {
            if(vis[v])continue;
            dsu.merge(u,v);
            dfs(v);
        }
    };
    for(int i=1;i<=n;i++)
    {
        if(!vis[dsu.find(i)])
        {
            dfs(i);
            vis[dsu.find(i)] = 1;
            ans += dsu.w[dsu.find(i)];
        }
    }
    cout<<ans;

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