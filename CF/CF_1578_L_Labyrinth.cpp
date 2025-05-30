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
        return w>t.w;
    }
};

void work()
{
    int n,m;cin>>n>>m;
    vector<int> a(2*n+1),sm(2*n+1),dp(2*n+1,lnf);
    for(int i=1;i<=n;i++)
        cin>>a[i],sm[i] = a[i];

    vector<Edge> e(m+1);

    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        e[i] = {u,v,w};
    }

    sort(++e.begin(),e.end());
    vector<int> g[2*n+1];
    DSU dsu(2*n);
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
        dsu.fa[fu]=dsu.fa[fv]=idx;
        sm[idx] = sm[fu] + sm[fv];

        dp[idx] = max(min(w - sm[fu],dp[fv] - sm[fu]),
                      min(w - sm[fv],dp[fu] - sm[fv]));
    }

    if(dp[idx]<=0)
    {
        cout<<"-1\n";
    }
    else
        cout<<dp[idx];
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

//     int t=1;
//     cin>>t;
//     while(t--)
    work();
}