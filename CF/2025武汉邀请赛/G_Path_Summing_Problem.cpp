#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
const int p = 998244353;
int inv[N],fac[N];
int C(int n,int m)
{
    if(m>n)return 1;
    if( m== 0)return 0;
    return fac[n] *inv[m] %p * inv[n-m]%p;
}
int qp(int a,int b)
{
    int ans = 1;
    while(b)
    {
        if(b&1)
            ans *= a,ans%=p;
        a *=a,a%=p;
        b>>=1;
    }
    return ans;
}
void work()
{
    int n,m;cin>>n>>m;
    vector<vector<int>> g(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>g[i][j];
    if(m<n)
    {
        vector<vector<vector<int>>> dp(2,vector<vector<int>>(m+1,vector<int>(n*m+1)));
        for(int i=1;i<=m;i++)
            dp[1][i][g[i][1]] = 1;
        for(int i=2;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                if(j==1)
                    dp[i%2][j][g[i][j]] = C(i+j-3,i-1)%p;
                else
                    dp[i%2][j][g[i][j]] = C(i+j-3,i-1)*2%p;
            }

        int ans = 0;
        for(int i=1;i<=n*m;i++)
            ans += dp[n%2][m][i];
        cout<<ans<<"\n";
    }
    else
    {
        vector<vector<vector<int>>> dp(2,vector<vector<int>>(n+1,vector<int>(n*m+1)));
        for(int i=1;i<=n;i++)
            dp[1][i][g[i][1]] = 1;
        for(int i=2;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                // C(i+j-2,i-1)
                if(j==1)
                    dp[i%2][j][g[j][i]] +=(C(i+j-3,i-1))%p;
                else
                    dp[i%2][j][g[j][i]] =C(i+j-3,i-1)*2%p;
            }

        int ans = 0;
        for(int i=1;i<=n*m;i++)
            ans += dp[m%2][n][i];
        cout<<ans<<"\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    fac[1] = inv[1] = 1;
    for(int i=2;i<N;i++)
        fac[i] = fac[i-1] * i,fac[i]%=p,inv[i] = qp(fac[i],2);
    int t=1;
    cin>>t;
    while(t--)
        work();
}