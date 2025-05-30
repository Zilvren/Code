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
    int u,v,l,a;
    bool operator<(Edge t) const
    {
        return a>t.a;
    }
};
struct Node
{
    int d,i;
    bool operator<(Node t)const
    {
        return d>t.d;
    }
};
void work()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(2 * n + 1);

    vector<Edge> e(m + 1);
    vector<int> lg(2*n + 1);

    for (int i = 2; i <= 2*n; i++)
        lg[i] = lg[i / 2] + 1;
    vector<array<int, 2>> g1[n + 1];
    vector<int> dist(n + 1, lnf);
    vector<bool> vis(n + 1);

    auto add = [&](int u, int v, int c)
    {
        g1[u].push_back({v, c});
    };

    auto dijsktra = [&]()
    {
        priority_queue<Node> Q;
        Q.push({0, 1});
        dist[1] = 0;
        while (Q.size())
        {
            auto [d, u] = Q.top();
            Q.pop();
            if (vis[u])continue;
            vis[u] = true;
            for (auto &t: g1[u])
            {
                auto [v, w] = t;
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    Q.push({dist[u] + w, v});
                }
            }
        }
    };

    vector<vector<int>> fa(2*n + 1, vector<int>(lg[2*n] + 1));
    for (int i = 1; i <= m; i++)
    {
        int u, v, l, a;
        cin >> u >> v >> l >> a;
        e[i] = {u, v, l, a};
        add(u, v, l);
        add(v, u, l);
    }
    dijsktra();
    sort(++e.begin(), e.end());
    vector<int> g2[2 * n + 1];
    DSU dsu(2 * n);
    int idx = n;
    vector<int> Min(2*n+1);
    for(int i=1;i<=n;i++)
        Min[i] = dist[i];
    for (int i = 1; i <= m; i++)
    {
        auto [u, v, l, at] = e[i];
        if (dsu.same(u, v))continue;
        int fu = dsu.find(u), fv = dsu.find(v);
        g2[++idx].push_back(fu);
        g2[fu].push_back(idx);
        g2[fv].push_back(idx);
        g2[idx].push_back(fv);
        a[idx] = at;
        Min[idx] = min(Min[fu],Min[fv]);
        dsu.fa[fu] = dsu.fa[fv] = idx;
        fa[fu][0] =fa[fv][0] = idx;
    }
    for (int j = 1; j <= lg[idx]; j++)
        for (int i = 1; i <= idx; i++)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];

    auto query = [&](int u,int p)
    {
        for(int i= lg[idx];i>=0;i--)
        {
            if(fa[u][i]&&a[fa[u][i]]>p)
                u = fa[u][i];
        }
        return Min[u];
    };
    int q, k, s;
    cin >> q >> k >> s;
    int lastans = 0;
    while (q--)
    {
        int v, p;
        cin >> v >> p;
        v = (v + k * lastans-1) % n + 1;
        p = (p + k * lastans) % (s + 1);
        cout<<(lastans = query(v,p))<<"\n";
    }
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