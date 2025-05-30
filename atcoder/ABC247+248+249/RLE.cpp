#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
int p;
int qp(int a,int b)
{
    int ans = 1;
    while(b)
    {
        if(b&1)
            ans *= a,ans%=p;
        a *= a,a %=p;
        b>>=1;
    }
    return ans;
}
void work()
{
    int n;cin>>n>>p;

    vector<vector<int>> dp(n+1,vector<int>(n+1));
    vector<vector<int>> pre(n+1,vector<int>(n+1));
    //dp[i][j][k]表示前i位缩减成j位可能的方案数
    dp[0][0] = 1;
    pre[0][0] = 1;
    auto Sum=[&](int l,int r,int k)
    {
        if(r<0||k<0)return (ll)0;
        if(l<=0)
            return pre[r][k];
        return (pre[r][k] + p - pre[l-1][k])%p;
    };
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            for(int k=1;k<=4;k++)
            {
                dp[i][j] += Sum(i-pow(10,k)+1,i-pow(10,k-1),j - k -1)*25%p;
                dp[i][j] %= p;
            }
            pre[i][j] = (pre[i-1][j] + dp[i][j])%p;
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++)
        ans += dp[n][i],ans %=p;

    ans=ans*26%p*qp(25,p-2)%p;
    cout<<ans;
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