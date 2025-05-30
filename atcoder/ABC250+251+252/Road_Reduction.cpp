#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
struct Node
{
    int u,s,i;
    bool operator<(Node t)const
    {
        return s>t.s;
    }
};
void work()
{
    int n,m;cin>>n>>m;
    vector<array<int,3>> g[n+1];

    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w,i});
        g[v].push_back({u,w,i});
    }

    vector<int> dist(n+1,lnf);
    vector<bool> vis(n+1);
    vector<int> ans(n+1);
    auto dijsktra = [&]()
    {
        priority_queue<Node> Q;
        Q.push({1,0,0});
        dist[1] = 0;
        while(Q.size())
        {
            auto [u,s,i] = Q.top();
            Q.pop();

            if(vis[u])continue;
            vis[u] = 1;
            ans[u] = i;
            for(auto &[v,w,i]:g[u])
            {
                if(dist[v] > w + dist[u])
                {
                    dist[v] = w + dist[u];
                    Q.push({v,dist[v],i});
                }
            }
        }
    };
    dijsktra();

    for(int i=2;i<=n;i++)
        cout<<ans[i]<<" ";

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