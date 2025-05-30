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
        if(x != fa[x])fa[x] = find(fa[x]);
        return fa[x];
    }
    bool merge(int x,int y)
    {
        int fx = find(x),fy = find(y);
        if(x==y)return false;
        fa[fx] = fy;
        return true;
    }
    bool same(int x,int y)
    {
        return find(x)==find(y);
    }
};
void work()
{
    int n;cin>>n;
    vector<int> p(n+1),d(n+1),in(n+1),g[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        g[i].push_back(p[i]);
        in[p[i]]++;
    }
    for(int i=1;i<=n;i++)
        cin>>d[i];
    DSU dsu(n);
    vector<bool> vis(n+1);
    auto topu = [&]()
    {
        queue<int> Q;
        for(int i=1;i<=n;i++)
        {
            if(in[i] == 0)
                Q.push(i);
        }
        while(Q.size())
        {
            int u = Q.front();Q.pop();
            if(vis[u]) continue;
            vis[u] = true;

            for(auto &v:g[u])
            {
                if(!vis[v])
                {
                    in[v]--;
                    if(in[v] == 0)
                        Q.push(v);
                }
            }
        }
    };
    topu();
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        int v = p[i];
        vis[i] = true;
        while(v != i)
        {
            dsu.merge(i,v);
            v = p[v];
            vis[v] = true;
        }
    }
    map<int,int> mp;
    for(int i=1;i<=n;i++)
    {
        mp[dsu.find(i)]++;
    }
    int now = 0;
    vector<bool> added(n+1);
    for(int i=1;i<=n;i++)
    {
        if(added[dsu.find(d[i])])
        {
            cout<<now<<" ";
            continue;
        }
        now += mp[dsu.find(d[i])];
        added[dsu.find(d[i])] = true;
        cout<<now<<" ";
    }
    cout<<"\n";
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