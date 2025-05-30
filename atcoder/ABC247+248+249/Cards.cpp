#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
const int p = 998244353;
struct DSU
{
    vector<int> fa,cnt;
    DSU(int n):fa(n+1),cnt(n+1,1){iota(fa.begin(),fa.end(),0);}
    int find(int x)
    {
        if( fa[x] != x )
            fa[x] = find(fa[x]);
        return fa[x];
    }


    bool merge(int x,int y)
    {
        int fx = find(x),fy = find(y);
        if(fx == fy )
            return false;
        fa[fx] = fy;
        cnt[fy] += cnt[fx];
        return true;
    }
};
void work()
{
    int n;cin>>n;
    vector<array<int,2>>e(n+1);

    for(int i=1;i<=n;i++)
        cin>>e[i][0];
    
    for(int i=1;i<=n;i++)
        cin>>e[i][1];
    DSU d(n);
    for(int i=1;i<=n;i++)
    {
        auto [u,v] = e[i];
        d.merge(u,v);
    }
    vector<int> f (n+1);
    f[1] = 1;
    f[2] = 3;
    for(int i=3;i<=n;i++)
        f[i] = f[i-1] + f[i-2],f[i]%=p;
    vector<bool> vis(n+1);
    int ans = 1;
    for(int i=1;i<=n;i++)
    {
        if(vis[d.find(i)])continue;
        ans *= f[d.cnt[d.find(i)]];
        ans %= p;
        vis[d.find(i)] = 1;
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