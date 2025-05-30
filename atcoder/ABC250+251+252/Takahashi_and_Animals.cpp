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
    for(int i=1;i<=n;i++)
        cin>>a[i];

    vector<vector<int>> dp(n+1,vector<int>(2,lnf));

    //dp[i][0]代表前i个点的边已经选完i不选的最大
    //dp[i][1]代表前i个点的边已经选完i选的最大
    int ans = lnf;
    dp[0][1] = a[n];
    dp[0][0] = lnf;
    for(int i=1;i<n;i++)
    {
        dp[i][0] = dp[i-1][1];
        dp[i][1] = min(dp[i-1][1],dp[i-1][0]) + a[i];
    }
    ans = min(dp[n-1][0],dp[n-1][1]);
    dp.assign(n+1,vector<int>(2,lnf));
    dp[0][1] = lnf;
    dp[0][0] = 0;
    for(int i=1;i<=n;i++)
    {
        dp[i][0] = dp[i-1][1];
        dp[i][1] = min(dp[i-1][1],dp[i-1][0]) + a[i];
    }
    ans = min(ans, min(dp[n][0],dp[n][1]));
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