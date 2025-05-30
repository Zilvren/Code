#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
struct DSU
{
    vector<int> fa,cnt;
    DSU(int n):fa(n+1),cnt(n+1,1){iota(fa.begin(),fa.end(),0);}


    int find(int x)
    {
        if(x!=fa[x])
            fa[x] = find(fa[x]);
        return fa[x];
    }

    bool merge(int x,int y)
    {
        int fx = find(x),fy = find(y);
        if(fx==fy)
            return false;
        fa[fx] = fy;
        cnt[fy] += cnt[fx];
        return true;
    }
};
void work()
{
    int n,m;cin>>n>>m;
    vector<int> g[n+1];
    vector<int> in(n+1);
    for(int i=1;i<=m;i++)
    {
        int u,v;cin>>u>>v;
//        g[u].push_back(v);
        g[v].push_back(u);
        in[u] ++ ;
    }
    vector<int> t = in;
    vector<int> dp(n+1,1);
    DSU dsu(n);
    vector<bool> vis(n+1);

    auto topu = [&]()
    {
        queue<int> Q;
        for(int i=1;i<=n;i++)
        {
            if(in[i] == 0)
            {
                Q.push(i);
            }
        }
        while(Q.size())
        {
            int u = Q.front();
            Q.pop();
            vis[u] = 1;
            for(auto &v:g[u])
            {
                in[v] --;
                if(in[v] == 0)
                    Q.push(v);
            }
        }
    };

    topu();
    int ans = 0;
    queue<int> Q;
    for(int i=1;i<=n;i++)
        if(!vis[i])
            Q.push(i);


    while(Q.size())
    {
        int u = Q.front();
        Q.pop();
        if(vis[u])continue;
        vis[u] = 1;
        ans++;
        for(auto &v:g[u])
        {
            t[v] --;
            if(t[v] == 0)
            {
                Q.push(v);
                dsu.merge(v,u);
            }
        }
    }


    cout<<ans<<"\n";



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