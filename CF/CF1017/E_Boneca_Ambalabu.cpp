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
    int sum = 0;
    for(int i=1;i<=n;i++)
        cin>>a[i],sum += a[i];

    vector<int> cnt(32);

    for(int i=1;i<=n;i++)
    {
        int p = 1;
        int t = a[i];
        while(t)
        {
            if(t&1)
                cnt[p]++;
            t>>=1;
            p++;
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        int p = 1;
        int t = a[i];
        int res = 0;
        while(t)
        {
            if(t&1)
            {
                res += (n - 2*cnt[p])*(1<<(p-1));
            }
            t>>=1;
            p++;
        }
        ans = max(ans,sum + res);
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