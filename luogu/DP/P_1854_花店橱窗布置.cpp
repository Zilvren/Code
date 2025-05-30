#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,m;cin>>n>>m;
    vector<vector<int>> g(n+1,vector<int>(m+1));

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>g[i][j];

    vector<vector<int>> dp(n+1,vector<int>(m+1,-lnf));
    for(int i=0;i<=m;i++)
        dp[0][i] = 0;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=0;k<j;k++)
                dp[i][j] = max(dp[i][j],dp[i-1][k]+g[i][j]);

    int ans = -lnf,p = -1;
    for(int i=1;i<=m;i++)
    {
        if(dp[n][i]>ans)
            ans = max(ans,dp[n][i]), p =i;
    }


    cout<<ans<<"\n";
    vector<int> path;
    path.push_back(p);
    for(int i=n;i>=2;i--)
    {
        for(int j=p-1;j>=1;j--)
        {
            if(dp[i-1][j] == dp[i][p] - g[i][p])
            {
                path.push_back(j);
                p = j;
                break;
            }
        }
    }
    for(int i = path.size()-1;i>=0;i--)
        cout<<path[i]<<" ";
    // for(int i=1;i<=n;i++)
    //     for(int j=1;j<=m;j++)
    //         cout<<dp[i][j]<<" \n"[j==m];
        
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