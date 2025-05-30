#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
const int p = 998244353;
void work()
{
    int n,m,k,s,t,x;cin>>n>>m>>k>>s>>t>>x;
    vector<int> g[n+1];

    for(int i=1;i<=m;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(2)));
    vector<vector<vector<bool>>> vis(n+1,vector<vector<bool>>(k+1,vector<bool>(2)));
    dp[s][0][0] = 1;
    //dp[i][s][0]
    auto bfs = [&]()
    {
        queue<array<int,3>> Q;
        Q.push({s,0,0});
        while(Q.size())
        {
            auto [u,s,c] = Q.front();
            Q.pop();

            if(s == k)
                continue;
            if(vis[u][s][c])continue;
            vis[u][s][c] = 1;
            for(auto &v:g[u])
            {
                if(v == x)
                {
                    dp[v][s+1][(c+1)%2] += dp[u][s][c];
                    dp[v][s+1][(c+1)%2]%=p;
                    Q.push({v,s+1,(c+1)%2});
                }
                else
                {
                    dp[v][s+1][c] += dp[u][s][c];
                    dp[v][s+1][c]%=p;
                    Q.push({v,s+1,c});
                }
            }
//            cout<<dp[t][k][0]<<"\n";
        }
    };
    bfs();
    cout<<dp[t][k][0]<<"\n";
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