#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,d;
    cin>>n>>d;
    vector<int> cnt(1e6+7);
    vector<bool> vis(1e6+7);
    vector<int> ans(d+1);
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }

    vector<vector<int>> dp(1e6+7,vector<int>(2));
    //dp[i][0]表示该数不删
    //dp[i][1]表示该数要删
    for(int i=0;i<=d;i++)
        dp[i][1] = cnt[i];
    for(int i = d;i<=1e6;i++)
    {
        dp[i][0] = dp[i-d][1];
        dp[i][1] = min(dp[i-d][0],dp[i-d][1]) + cnt[i];
        ans[i%d] = min(dp[i][0],dp[i][1]);
    }
    int res =0 ;
    for(int i=0;i<d;i++)
        res+=ans[i];
    cout<<res;

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