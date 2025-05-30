#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n;cin>>n;
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(2)));
    int p;cin>>p;


    //dp[i][j][0]表示前i列删了j条边且前i列不联通
    //dp[i][j][1]表示前i列删了j条边且前i列联通
    for(int i=1;i<=n;i++)
    {
        dp[i][0][1] = 1;
    }
    dp[1][1][0] = dp[1][0][1] = 1;
    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++)
        {
            dp[i][j][1] = (dp[i-1][j-1][1]*3%p + dp[i-1][j][0]%p)%p + dp[i-1][j][1],dp[i][j][1] %=p;
            
            dp[i][j][0] = dp[i-1][j-1][0]%p;
            if(j-2>=0)
              dp[i][j][0] += dp[i-1][j-2][1]*2%p,dp[i][j][0] %= p; 
        }
    
    for(int i=1;i<n;i++)
    {
        cout<<dp[n][i][1]<<" ";
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