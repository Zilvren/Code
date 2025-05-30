#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
int dist[310][310];
int cnt[310][310];
struct Edge
{
    int u,v,w;
};
void work()
{
    memset(dist,0x3f,sizeof dist);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
        dist[i][i] = 0;
    vector<Edge> e(m+1);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        dist[u][v] = min(dist[u][v],w);
        dist[v][u] = min(dist[v][u],w);
        cnt[u][v] = 1;
        cnt[v][u] = 1;
        e[i] = {u,v,w};
    }


    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(dist[i][k] + dist[k][j] == dist[i][j])
                    cnt[i][j] = cnt[i][k] + cnt[k][j];
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }


    int ans = 0;
    for(int i=1;i<=m;i++)
    {
        auto [u,v,w] = e[i];

        if(dist[u][v] < w)
        {
            ans++;
        }
        if(dist[u][v] == w&&cnt[u][v] >=2)
        {
            ans++;
        }
    }
    cout<<ans<<"\n";
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