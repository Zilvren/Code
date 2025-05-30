#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
struct node
{
    int d,u;
    node(int d,int i):d(d),u(i){}
    bool operator <(node t) const
    {
        return d>t.d;
    }
};


void worn()
{
    int n,m;
    cin>>n>>m;
    vector<int> to(2*m+m*4*n+1),ne(2*m+m*4*n+1),from(2*m+m*4*n+1),h(n+n*n+1,-1),w(2*m+m*4*n+1);
    vector<int> dist(n+n*n+1,lnf);
    vector<bool> vis(n+n*n+1);
    int s,t;cin>>s>>t;
    s++,t++;
    int idx = 0;
    auto add=[&](int u,int v,int c)
    {
        from[idx] = u;
        to[idx] = v;
        ne[idx] = h[u];
        w[idx] = c;
        h[u] = idx++;
    };
    vector<array<int,3>> e(m+1);
    for(int i=1;i<=m;i++)
    {
        cin>>e[i][0]>>e[i][1]>>e[i][2];

    }
    vector<int> s(n+1);

    for(int i=1;i<=n;i++)
        cin>>s[i];

    for(int i=1;i<=m;i++)
    {
        auto [a,b,c] = e[i];
        add(a,b,c);
        add(b,a,c);
        for(int j=1;j<=n;j++)
        {
            add(a+(j-1)*n,b+j*n,0);
            add(b+(j-1)*n,a+j*n,0);
            add(a+j*n,b+j*n,c*s[j]);
            add(b+j*n,a+j*n,c);
        }
    } 

    auto dijsntra = [&]()
    {
        priority_queue<node> Q;
        Q.push({0,s});
        dist[s] = 0;
        while(Q.size())
        {
            auto [u,d] = Q.top();
            Q.pop();
            if(vis[u])continue;
            vis[u] = true;
            for(int i = h[u];i!=-1;i = ne[i])
            {
                int v = to[i];
                if(dist[v]>dist[u] + w[i])
                {
                    dist[v]=dist[u] + w[i];
                    Q.push({dist[v],v});
                }

            }
        }
    };
    dijsntra();
    int Min =lnf;
    for(int i=0;i<=n;i++)
        Min = min(Min,dist[t+i*n]);
    cout<<Min;
    
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   int t=1;
   cin>>t;
   while(t--)
    worn();
    
    return 0;
}