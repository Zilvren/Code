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

    vector<vector<int>> dp((1<<n)+1,vector<int>(n+1,lnf));
    
    //dp[s][i] 到达以s为状态i为结尾的最短路径
    auto bfs = [&]()
    {
        queue<array<int,2>> Q;
        for(int i=1;i<=n;i++)
            Q.push({1<<(i-1),i}),dp[1<<(i-1)][i] = 1,dp[0][i] = 0;


        while(Q.size())
        {
            auto [s,u] = Q.front();
            Q.pop();

            for(auto &v:g[u])
            {
                if(dp[s^(1<<(v-1))][v] > dp[s][u] + 1)
                {
                    dp[s^(1<<(v-1))][v] = dp[s][u] + 1;
                    Q.push({s^(1<<(v-1)),v});
                }
            }
        }
    };
    bfs();

    int ans = 0;

    for(int i=0;i<(1<<n);i++)
    {
        int t = lnf;
        for(int j=1;j<=n;j++)
        {
            t = min(t,dp[i][j]);
        }
        ans += t;
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