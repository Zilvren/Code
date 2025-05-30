#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
struct Node
{
    int v,s;
};
void work()
{
    int n;cin>>n;
    vector<Node> g[n+1];

    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back({v,1});
        g[v].push_back({u,1});
    }
    vector<int> size(n+1);

    function<void(int,int)> dfs = [&](int u,int fa)
    {
        size[u] = 1;

        for(auto &[v,s]:g[u])
        {
            if(v == fa)continue;

            dfs(v,u);
            s = size[v];
            size[u] += size[v];
        }
        for(auto &[v,s]:g[u])
        {
            if(v== fa)
            {
                s = n-size[u];
                break;
            }
        }
    };

    dfs(1,0);

    for(int u=1;u<=n;u++)
    {
        int smt = 0;
        int pre = 0;
        int sm = 0;
        for(auto &[v,s]:g[u])
        {
            smt += pre*s;
            pre += s;
            sm += s;
        }
        int ans = 0;
        for(auto &[v,s]:g[u])
        {
            ans += s*(smt - s*(sm - s)) + s + s*(sm-s);
        }
        cout<<ans + smt + n<<" ";
    }
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