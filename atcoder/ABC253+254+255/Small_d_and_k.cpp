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
    for(int i=1;i<=m;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }


    int q;cin>>q;
    while(q--)
    {
        int x,k;cin>>x>>k;
        int ans = 0;
        auto bfs = [&]()
        {
            queue<array<int,2>> Q;
            vector<bool> vis(n+1);
            Q.push({x,0});

            while(Q.size())
            {
                auto u = Q.front()[0],s = Q.front()[1];
                Q.pop();
                if(vis[u])continue;
                vis[u] = 1;
                if(s > k)
                    continue;
                ans += u;
                for(auto &v:g[u])
                {
                    Q.push({v,s+1});
                }
            }
        };
        bfs();
        cout<<ans<<"\n";
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