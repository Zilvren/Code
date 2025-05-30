#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
struct DSU
{
    vector<int> fa,cv,ce;

    DSU(int n):fa(n+1),cv(n+1,1),ce(n+1){
        iota(fa.begin(),fa.end(),0);
    }

    int find(int x)
    {
        if(fa[x] != x)
            fa[x] = find(fa[x]);

        return fa[x];
    }
    bool merge(int x,int y)
    {
        int fx = find(x),fy = find(y);
        if(fx!=fy)
        {
            if(cv[fx] + cv[fy]>=ce[fx] + ce[fy] + 1)
            {
                cv[fy] += cv[fx];
                ce[fy] += ce[fx] + 1;
                fa[fx] = fy;
                return true;
            }
            else
                return false;
        }
        else
        {
            if(cv[fx] >= ce[fx]+ 1)
            {
                ce[fy] ++;
                return true;
            }
            else
                return false;
        }
        return false;
    }

};
struct Edge
{
    int u,v,w;
};
void work()
{
    int n,m;cin>>n>>m;
    vector<Edge> e(m+1);
    for(int i=1;i<=m;i++)
    {
        cin>>e[i].u>>e[i].v>>e[i].w;
    }

    sort(++e.begin(),e.end(),[&](Edge a,Edge b)
    {
        return a.w > b.w;
    });

    int ans = 0;
    DSU dsu(n);
    for(int i=1;i<=m;i++)
    {
        auto [u,v,w] = e[i];
        if(dsu.merge(u,v))
        {
            ans += w;
        }
    }
    cout<<ans<<"\n";
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