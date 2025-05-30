#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n;cin>>n;
    vector<int> g[n+1];
    vector<int> in(n+1);
    for(int i=1;i<=n;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        in[u]++;
        in[v]++;
    }
    vector<bool> vis(n+1,true);
    auto topu = [&]()
    {
        queue<int> Q;
        for(int i=1;i<=n;i++)
        {
            if(in[i] == 1)
            {
                Q.push(i);
            }
        }

        while(Q.size())
        {
            int u = Q.front();
            Q.pop();
            vis[u] = false;
            for(auto &v:g[u])
            {
                in[v]--;
                if(in[v] == 1)
                {
                    Q.push(v);
                }
            }
        }
    };
    topu();
    vector<int> dis(n+1,lnf);
    function<void(int,int)> dfs = [&](int u,int fa)
    {
        for(auto&v:g[u])
        {
            if(fa == v||vis[v])continue;
            dis[v] = dis[u] + 1;
            dfs(v,u);
        }
    };

    for(int i=1;i<=n;i++)
    {
        if(vis[i])
        {
            dis[i] = 0;
            dfs(i,0);
        }
    }
    for(int i=1;i<=n;i++)
    cout<<dis[i]<<" ";
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