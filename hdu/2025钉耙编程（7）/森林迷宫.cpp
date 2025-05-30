#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
struct Edge
{
    int v,w1,w2;
};
void work()
{
    int n;cin>>n;
    vector<Edge> g[n+1];
    for(int i=1;i<n;i++)
    {
        int u,v,w1,w2;
        cin>>u>>v>>w1>>w2;
        g[u].push_back({v,w1,w2});
        g[v].push_back({u,w2,w1});
    }
    int s,t;cin>>s>>t;
    vector<int> patht;
    vector<bool> path(n+1);

    vector<int> dp(n+1);
    function<void(int,int)> dfs = [&](int u,int fa)
    {
        for(auto &[v,w1,w2]:g[u])
        {
            if(v == fa)continue;
            dfs(v,u);
            if(path[v])continue;
            dp[u] += max(dp[v]+w1+w2,(ll)0);
        }
    };
    path[s] = path[t] = 1;
    int res = 0;
    function<void(int,int,int)> get_path = [&](int u,int fa,int s)
    {
        if(u == t)
        {
            for(auto &c:patht)
                path[c]=1;
            res = s;
            return ;
        }
        for(auto &[v,w1,w2]:g[u])
        {
            if(v == fa)continue;
            patht.push_back(v);
            get_path(v,u,s + w1);
            patht.pop_back();
        }
    };
    get_path(s,0,0);
    dfs(s,0);
    for(int i=1;i<=n;i++)
    {
        if(path[i])
        {
            res += dp[i];
        }
    }
    cout<<res<<"\n";
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