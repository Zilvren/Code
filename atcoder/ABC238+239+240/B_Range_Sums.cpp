#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,q;cin>>n>>q;

    vector<bool> dp(n+1);
    dp[0] = 1;

    vector<int> g[n+1];

    for(int i=1;i<=q;i++)
    {
        int u,v;cin>>u>>v;
        g[v].push_back(u-1);
        g[u-1].push_back(v);
    }
    
    vector<bool> vis(n+1);

    function<void(int)> dfs = [&](int u)
    {
        if(vis[u])return;
        vis[u] = 1;
        vector<int> t = g[u];
        for(int i=t.size()-1;i>=0;i--)
        {
            int v = t[i];
            g[u].pop_back();
            dfs(v);
        }

    };
    dfs(0);
    cout<<((vis[n])?"Yes":"No");

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