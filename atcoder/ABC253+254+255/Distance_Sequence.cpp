#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
const int p = 998244353;
void work()
{
    int n,m,k;cin>>n>>m>>k;
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    vector<vector<int>> pre(n+1,vector<int>(m+1));
    //dp[i][j] 表示i个数 当前数为j的方案数

    for(int i=1;i<=m;i++)
        dp[1][i] = 1,pre[1][i] = pre[1][i-1] + dp[1][i],pre[1][i]%=p;
    for(int i=2;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            dp[i][j] += (pre[i-1][max((ll)0,j - k)]+ (pre[i-1][m] - pre[i-1][min(m,j+k-1)]+p)%p)%p;
            dp[i][j] %=p;
            if(k == 0)
                dp[i][j] = pre[i-1][m];
            pre[i][j] = pre[i][j-1] + dp[i][j];
            pre[i][j] %=p;
        }

    int ans = 0;
    for(int i=1;i<=m;i++)
        ans += dp[n][i],ans%=p;

    cout<<pre[n][m]<<"\n";
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