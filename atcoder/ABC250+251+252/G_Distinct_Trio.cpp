#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n;cin>>n;
    vector<int> a(n+1);
    map<int,int> mp;
    for(int i=1;i<=n;i++)
        cin>>a[i],mp[a[i]]++;

    vector<array<int,2>> cnt;
    cnt.push_back({0,0});
    for(auto &[f,s]:mp)
        cnt.push_back(array<int,2>{f,s});

    vector<int>pre(cnt.size()),suf(cnt.size()+1);

    for(int i=1;i<cnt.size();i++)
        pre[i] = pre[i-1] + cnt[i][1];
    for(int i=cnt.size()-1;i>=1;i--)
        suf[i] = suf[i+1] + cnt[i][1];

    int ans = 0;
    for(int i=2;i<cnt.size()-1;i++)
    {
        ans += cnt[i][1] *pre[i-1]*suf[i+1];
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