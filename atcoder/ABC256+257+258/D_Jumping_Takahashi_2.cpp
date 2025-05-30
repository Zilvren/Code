#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
struct Edge
{
    int u,v,w;
};
struct Node
{
    int u,w;
    bool operator<(Node t)const
    {
        return w>t.w;
    }
};
void work()
{
    int n;cin>>n;
    vector<array<int,3>> a(n+1);

    for(int i=1;i<=n;i++)
        cin>>a[i][0]>>a[i][1]>>a[i][2];

    int ans = lnf;
    vector<Edge> e;
    vector<array<int,2>> g[n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            auto [x1,y1,p1] = a[i];
            auto [x2,y2,p2] = a[j];
            g[i].push_back({j,(abs(x2-x1) + abs(y2-y1) +p1-1)/ p1});
            g[j].push_back({i,(abs(x2-x1) + abs(y2-y1) +p2-1)/ p2});
        }
    }

    auto prim = [&](int i)
    {
        int res = 0;
        vector<int> dis(n+1,lnf);
        vector<bool> vis(n+1);
        priority_queue<Node> Q;
        Q.push({i,0});
        dis[i] = 0;
        while(Q.size())
        {
            auto [u,w] = Q.top();
            Q.pop();
            if(vis[u])continue;
            vis[u] = 1;
            res = max(res,w);
            for(auto [v,ew]:g[u])
            {
                if(dis[v] > ew)
                {
                    dis[v] = ew;
                    Q.push({v,dis[v]});
                }
            }
        }
        return res;
    };
    for(int i=1;i<=n;i++)
        ans = min(ans,prim(i));
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