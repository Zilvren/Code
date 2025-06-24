#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];

    vector<int> in(n+1);
    vector<array<int,2>> g[n+1];

    for(int i=1;i<n;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        in[v] ++;
        in[u] ++;
    }
    int ans =0 ;
    
    auto topu = [&]()
    {
        queue<int> Q;
        vector<bool> vis(n+1);
        for(int i=1;i<=n;i++)
        {
            if(in[i] == 1)
             Q.push(i);
        }
        while(Q.size())
        {
            int u = Q.front();
            Q.pop();
            vis[u] = 1;
            for(auto &[v,w]:g[u])
            {
                if(vis[v])continue;
                a[v] += a[u];
                ans += w*(abs(a[u]));
                in[v] -- ;
                if(in[v] == 1)
                    Q.push(v);
            }
        }
    };
    topu();
    cout<<ans;
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