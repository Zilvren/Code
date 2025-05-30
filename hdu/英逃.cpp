#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,x;cin>>n>>x;

    vector<int> a(n+2);
    int raw = 0;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    a[0] = a[1],a[n+1] =a[n];
    vector<int> lg(n+1);
    lg[0] = -1;
    for(int i=1;i<=n;i++)
        lg[i] = lg[i/2]+1;

    vector<vector<int>> f(n+1,vector<int>(lg[n]+2));
    for(int i=1;i<=n;i++)
        f[i][0] = a[i];

    for(int len = 1;len <= lg[n];len++)
        for(int i=1;i+(1<<(len-1))<=n;i++)
            f[i][len] = max(f[i][len-1] ,f[i+(1<<(len-1))][len-1]);

    auto Max = [&](int l,int r)
    {
        int len = lg[r-l+1];
        return max(f[l][len],f[r-(1<<(len))+1][len]);
    };

    vector<int> pre(n+1);

    for(int i=1;i<=n;i++)
        pre[i] = pre[i-1] + abs(a[i] - a[i-1]);

    vector<int> suf(n+2);
    for(int i=n;i>=1;i--)
        suf[i] = suf[i+1] + abs(a[i] - a[i+1]);

    int l = 1,r = n;int ans = -1;
    auto check = [&](int k)
    {
        for(int l =1;l+k-1<=n;l++)
        {
            int r = l+k-1;
            int t = pre[l-1]+suf[r+1];
            if(l-1>=1)
                t+=abs(Max(l,r) - a[l-1]);

            if(r+1<=n)
                t+=abs(Max(l,r) - a[r+1]);
            if(t<=x)
                return true;
        }
        return false;
    };
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(check(mid))
            r = mid-1,ans = mid;
        else
            l = mid+1;
    }
    if(ans == 1)
        ans = 0;
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