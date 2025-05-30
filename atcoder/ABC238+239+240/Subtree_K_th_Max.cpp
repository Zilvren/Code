#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
void work()
{
    int n,m;cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    vector<int> g[n+1];
    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<array<int,2>> query[n+1];
    vector<int> ans(m+1);
    for(int i=1;i<=m;i++)
    {
        int u,k;cin>>u>>k;
        query[u].push_back({k,i});
    }
    vector<multiset<int,greater<int>>> S(n+1);
    function<void(int,int)> dfs  = [&](int u,int fa)
    {

        for(auto &v:g[u])
        {
            if(v == fa)continue;
            dfs(v,u);
            for(auto &t:S[v])
                S[u].insert(t);
        }
        S[u].insert(a[u]);
        while(S[u].size()>20)
            S[u].erase(--S[u].end());
        vector<int> w;
        w.push_back(0);
        for(auto a:S[u])
            w.push_back(a);
        for(auto &[k,i]:query[u])
        {
            ans[i] = w[k];
        }
    };
    dfs(1,0);
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<"\n";
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