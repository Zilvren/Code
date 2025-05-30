#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,m;cin>>n>>m;
    vector<int> g[n+1];
    for(int i = 1;i<=m;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> vis(n+1);
    function<void(int)> dfs = [&](int u)
    {
        for(auto &v:g[u])
        {
            if(!vis[v])
            {
                vis[v] = 1;
                cout<<u<<" "<<v<<"\n";
                dfs(v);
            }
        }
    };
    vis[1] = 1;
    dfs(1);
    vis.assign(n+1,0);
    auto bfs = [&]()
    {
        queue<int> Q;
        vis[1] = 1;
        Q.push(1);
        while(Q.size())
        {
            int u = Q.front();
            Q.pop();

            for(auto &v: g[u])
            {
                if(!vis[v])
                {
                    vis[v] = 1;
                    Q.push(v);
                    cout<<u<<" "<<v<<"\n";
                }
            }
        }
    };
     bfs();
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