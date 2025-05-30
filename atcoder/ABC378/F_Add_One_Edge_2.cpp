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

    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> vis(n+1);
    int s = 0;
    function<void(int,int)> dfs = [&](int u,int fa)
    {
        if(g[u].size()!=3||vis[u])
            return ;
        vis[u] = 1;
        for(auto &v:g[u])
        {
            if(v == fa)continue;
            if(g[v].size() == 2)
                s++;
            dfs(v,u);
        }
    };
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        s = 0;
        dfs(i,0);
        ans += s*(s-1)/2;
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