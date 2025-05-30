#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
struct Edge
{
    int u,v,w,ne;
};
struct Node
{
    int w,u,d;
};
void work()
{
    int n,m;cin>>n>>m;
    vector<Edge> e(m*m+1);
    vector<int> h(m+1,-1);;

    vector<Node> node(m+1);
    string s;cin>>s;
    auto tf = [&](string t)
    {
        int ans = 0;
        int p = 1;
        for(int i=t.size()-1;i>=0;i--)
        {
            if(t[i] == '1')
                ans += p;
            p*=2;
        }
        return ans;
    };
    int st;st = tf(s);
    for(int i=1;i<=m;i++)
    {
        int w;
        string u,d;cin>>w>>u>>d;
        node[i] = {w,tf(u),tf(d)};
    }
    vector<int> dist((1<<n)+1,lnf);
    vector<bool> vis((1<<n)+1);
    auto spfa = [&]()
    {
        queue<int> Q;
        Q.push(st);
        dist[st] = 0;
        vis[st] = true;
        while(Q.size())
        {
            int u = Q.front();
            Q.pop();
            vis[u] = false;
            for(int i=1;i<=m;i++)
            {
                int f = (u-(u&node[i].u));
                int v = ((f|node[i].d)),w = node[i].w;
                if(dist[v]>dist[u]+w)
                {
                    dist[v]=dist[u]+w;
                    if(vis[v])continue;
                    Q.push(v);
                    vis[v] = true;
                }
            }
        }
    };
    spfa();
    if(dist[0] == lnf)
        cout<<-1<<"\n";
    else
    cout<<dist[0]<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--)
    work();
}