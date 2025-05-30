#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
const int p = 998244353;

void work()
{
    int n,k;cin>>n>>k;
    vector<array<int,3>> P(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>P[i][0];
        P[i][2] = i;
    }

    for(int i=1;i<=n;i++)
    {
        cin>>P[i][1];
    }

    sort(++P.begin(),P.end());

    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(n+2)));
    //dp[i][j][q] 表示前i个人选了j个(i-j)个中y最小的人的y为q时，有多少个方案
    dp[0][0][n+1] = 1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=min(i,k);j++)
            for(int q=1;q<=n+1;q++)
            {
                if(P[i][1] < q&&j)
                {
                    dp[i][j][q] += dp[i-1][j-1][q];
                    dp[i][j][q] %= p;
                }
                dp[i][j][min(P[i][1],q)] += dp[i-1][j][q];
                dp[i][j][min(P[i][1],q)] %=p;
            }
    
    int ans =0;
    for(int i=1;i<=n+1;i++)
        ans += dp[n][k][i],ans%=p;
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