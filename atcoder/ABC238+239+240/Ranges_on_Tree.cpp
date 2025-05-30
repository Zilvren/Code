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

    vector<array<int,2>> ans(n+1);
    function<void(int,int,int)> dfs = [&](int u,int fa,int l)
    {
        if(g[u].size() == 1&&u!=1)
        {
            ans[u] = {l,l};
            return ;
        }
        int R = l;
        for(auto &v:g[u])
        {
            if(v == fa)continue;
            dfs(v,u,R);
            R = ans[v][1]+1;
        }
        ans[u] = {l,R-1};
    };
    dfs(1,0,1);
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
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