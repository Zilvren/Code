#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n;cin>>n;
    vector<int> g[n+1];
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
        g[i].push_back(-lnf);
    
    for(int i=1;i<=n;i++)
    {
        cin>>a[i],g[a[i]].push_back(i);
    }

    for(int i=1;i<=n;i++)
        g[i].push_back(lnf);
    
    int q;cin>>q;
    while(q--)
    {
        int l,r,x;cin>>l>>r>>x;
        int p1 =lower_bound(g[x].begin(),g[x].end(),l) - g[x].begin();
        int p2 =upper_bound(g[x].begin(),g[x].end(),r) - g[x].begin();
        cout<<p2 - p1<<"\n";
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