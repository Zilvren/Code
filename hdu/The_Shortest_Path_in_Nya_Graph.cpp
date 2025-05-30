#include<bits/stdc++.h>
//#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
struct Node
{
    ll d,u;
    bool operator< (Node t)  const
    {
        return d>t.d;
    }
};
struct Edge
{
    int from,to,w,ne;
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t=1;
    cin>>t;
    for(int j=1;j<=t;j++)
    {
        int n,m,c;cin>>n>>m>>c;

        vector<int> p(n*3+5);
        vector<bool> k(n+2);
        vector<Edge> e(2*m+1+4*n);vector<int> h(n*3+5,-1);int idx = 0;
        auto add = [&](int u,int v,int w)
        {
            e[idx] = {u,v,w,h[u]};
            h[u] = idx++;
        };
        
        for(int i=1;i<=n;i++)
        {
            cin>>p[i];
            k[p[i]] = true;
        }

        for(int i=1;i<=n;i++)
        {
            int ls = n+p[i]-1;
            int nx = n+p[i];
            if(k[ls-n])
                add(i,ls,c),add(ls+n,i,0);
            if(k[nx-n])
                add(i,nx+n,c),add(nx,i,0);
        }

        priority_queue<Node> Q;

        for(int i=1;i<=m;i++)
        {
            int u,v,w;cin>>u>>v>>w;
            add(u,v,w);
            add(v,u,w);
        }

        vector<ll> dist(n*3+5,lnf);
        vector<bool> vis(n*3+5);
        auto dijsktra = [&]()
        {
            Q.push({0,1});
            dist[1] = 0;
            while(Q.size())
            {
                auto [d,u] = Q.top();Q.pop();
                if(vis[u]) continue;
                vis[u] = true;

                for(int i = h[u] ; i!=-1;i=e[i].ne)
                {
                    auto [f,v,w,ne] = e[i];
                    if(dist[v] > dist[u] + w)
                    {
                        dist[v] = dist[u] + w;
                        Q.push({dist[v],v});
                    }
                }
            }
        };
        dijsktra();
        cout<<"Case #"<<j<<": ";
        if(dist[n] == lnf)
            cout<<-1<<"\n";
        else
            cout<<dist[n]<<"\n";
    }
}