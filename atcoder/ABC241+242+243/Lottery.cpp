#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
const int mod = 998244353;
int qp(int a,int b)
{
    int ans = 1;
    while(b)
    {
        if(b&1)
            ans *= a,ans%=mod;
        a *= a,a%=mod;
        b>>=1;
    }
    return ans;
}
int fac[N],inv[N];
int C(int n,int m)
{
    if(m>n) return 0;
    return fac[n] * inv[n-m]%mod * inv[m]%mod;
}

void work()
{
    int n,m,k;cin>>n>>m>>k;

    vector<int> a(n+1);
    int sum = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum += a[i];
    }

    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(m+1)));
    //dp[i][j][p] 表示前i个已经抽了j次有p种不同的
    for(int i=0;i<=n;i++)
        dp[i][0][0] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            for(int p = 1;p<=min(i,m);p++)//第几个
            {
                dp[i][j][p] = dp[i-1][j][p];
                for(int q=1;q<=j;q++)
                {
                    dp[i][j][p] += dp[i-1][j - q][p-1]*C(j,q)%mod*qp(a[i]%mod*qp(sum,mod-2)%mod,q)%mod;
                    dp[i][j][p] %= mod;
                }
            }
        }
    }
    cout<<dp[n][k][m];
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    inv[0] = fac[0] = 1;
    for(int i=1;i<N;i++)
        fac[i] = fac[i-1] * i%mod,inv[i] = qp(fac[i],mod-2);
    // int t=1;
    // cin>>t;
    // while(t--)
        work();
}