#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
struct DSU
{
    vector<int> fa;
    vector<int> cnt;
    DSU (int n):fa(n+1),cnt(n+1)
    {
        iota(fa.begin(),fa.end(),0);
        for(int i=1;i<=n;i++)
            cnt[i] = 1;
    }

    int find(int x)
    {
        if(fa[x]!=x)
            fa[x] = find(fa[x]);
        return fa[x];
    }

    bool merge(int u,int v)
    {
        int fu = find(u),fv = find(v);
        if(fu == fv)return false;
        if(fv>fu)
            swap(fv,fu);
        cnt[fv] += cnt[fu];
        fa[fu] = fv;
        return true;
    }
    bool same(int u,int v)
    {
        return find(u) == find(v);
    }
};
void work()
{
    int n,m;cin>>n>>m;
    vector<int> g[n+1];

    auto add=[&](int u,int v)
    {
        g[u].push_back(v);
    };

    for(int i=1;i<=m;i++)
    {
        int a,b;cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    set<int> S;
    DSU dsu(n);
    S.insert(1);
    for(int i=1;i<=n;i++)
    {
        for(auto &v:g[i])
        {
            if(S.count(v)==0)
                S.insert(v);
            if(v<i)
                dsu.merge(i,v);
        }
        if(dsu.cnt[1] == i)
            cout<<S.size() - i<<"\n";
        else
            cout<<-1<<"\n";

    }
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