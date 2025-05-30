#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n;cin>>n;
    if(n==1)
    {
        cout<<0<<"\n";
        return ;
    }
    vector<int> g[n+1];

    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vector<int>> dp(n+1,vector<int>(4,0));
    //dp[i][0]表示开，
    //dp[i][1]表示关被孩子操作.
    //dp[i][2]表示操作其与其父亲.
    function<void(int,int)> dfs = [&](int u,int fa)
    {
        if(g[u].size() == 1&&u!=1)
        {
            dp[u][0] = 0;
            dp[u][1] = inf;
            dp[u][2] = 1;
            return;
        }
        dp[u][2] = 1;
        int sum = 0;
        for(auto &v:g[u])
        {
            if(v == fa)continue;
            dfs(v,u);
            sum+=min({dp[v][0],dp[v][1]});
            dp[u][0] += dp[v][1];
            dp[u][2] += min(dp[v][0],dp[v][1]);
        }

        int t = inf;
        for(auto &v:g[u])
        {
            if(v == fa)continue;
            t = min(t,dp[v][2]+sum - min({dp[v][0],dp[v][1]}));
        }
        dp[u][1] = t;
    };
    dfs(1,0);
    cout<<min({dp[1][0],dp[1][1]});
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