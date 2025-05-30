#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

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
    vector<int> dis1(n+1,lnf);
    dis1[1] = 0;
    int s = 0;
    function<void(int,int)> dfs = [&](int u,int fa)
    {
        if(s == 0||dis1[u] > dis1[s])
            s = u;
        for(auto &[v,w]:g[u])
        {
            if(v == fa)continue;
            dis1[v] = dis1[u] + w;
            dfs(v,u);
        }
    };
    dfs(1,0);
    int ed = s;

    dis1[s] = 0;
    dfs(s,0);
    vector<int> dis2 = dis1;
    int st = s;
    dis1[s] = 0;
    dfs(s,0);
    vector<int> path;
    vector<int> anspath;
    vector<bool> vis(n+1);
    function<void(int,int)> find_path = [&](int u,int fa)
    {
        if(u == ed)
        {
            anspath = path;
            for(auto &a:path)
                vis[a] = 1;
        }
        for(auto &[v,w]:g[u])
        {
            if(v == fa)continue;
            path.push_back(v);
            find_path(v,u);
            path.pop_back();
        }
    };
    path.push_back(st);
    find_path(st,0);

    function<int(int,int)> find_max_dis=[&](int u,int fa) -> int
    {
        int ans = 0;
        for(auto &[v,w]:g[u])
        {
            if(v == fa||vis[v])continue;
            ans = max(ans,find_max_dis(v,u) + w);
        }
        return ans;
    };
    int l = 0;
    for(int i=0;i<anspath.size();i++)
    {
        int ans = find_max_dis(anspath[i],0);
        if(ans == dis1[anspath[i]])
        {
            l = i;
            break;
        }
    }
    int ans = 0;
    for(int i=l;i>=0;i--)
    {
        int ans = find_max_dis(anspath[i],0);
        if(ans == dis2[anspath[i]])
        {
            ans = l-i;
        }
        else
            break;
    }

    cout<<dis1[s]<<"\n";
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