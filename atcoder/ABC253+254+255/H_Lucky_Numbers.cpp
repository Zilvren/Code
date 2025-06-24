#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,m;cin>>n>>m;
    vector<int> a(n+1),b(m+1),c(n+1);

    for(int i=1;i<n;i++)
        cin>>a[i];
        
    for(int i=1;i<=m;i++)
        cin>>b[i];

    for(int i=1;i<=n;i++)
        c[i] = a[i-1] - c[i-1];

    map<int,int> mp;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            mp[(c[i] - b[j])*(i%2?-1:1)]++;
    int ans = 0;
    for(auto &t:mp)
        ans = max(ans,t.second);
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