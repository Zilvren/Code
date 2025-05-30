#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
const int p = 1e9+7;
void work()
{
    int n;cin>>n;

    vector<array<int,2>> g[n+1];

    for(int i=1;i<n;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    vector<bool> vis(n+1);
    vector<int> dis(n+1);
    function<void(int,int,int)> dfs= [&](int u,int fa,int s)
    {
        dis[u] = s;
        for(auto &[v,w]:g[u])
        {
            if(v == fa)continue;
            dfs(v,u,s+w);
        }
    };
    dfs(1,0,0);
    int cntev = 0,cntod = 0;
    for(int i=1;i<=n;i++)
    {
        if(dis[i]%2 ==0)
            cntev++;
        else
            cntod++;
    }
    
    cout<<cntev*cntev*cntev+cntod*cntod*cntod<<"\n";
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