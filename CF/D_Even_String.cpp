#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
struct Node
{
    char c;
    int cnt;
};
const int p = 998244353;
vector<int> fac(5e5+7);
vector<int> inv(5e5+7);
int C(int n,int m)
{
    if(m>n)
        return 0;
    return fac[n]%p*inv[m]%p*inv[n-m]%p;
}
int qp(int a,int b)
{
    a %=p;
    int ans = 1;
    while(b)
    {
        if(b&1)
            ans *= a,ans%=p;
        b >>= 1;
        a = a*a%p;
    }
    return ans;
}
void work()
{
    vector<int> c(27);

    int sum = 0;
    vector<Node> v;
    for(int i=0;i<26;i++)
    {
        cin>>c[i],sum += c[i];
        if(c[i]!=0)
            v.push_back({char(i+'a'),c[i]});
    }
    int od = (sum+1)/2,ev = sum/2;

    vector<int> dp(sum+1);
    dp[0] = 1;
    for(int i=0;i<v.size();i++)
    {
        for(int j=sum;j>=v[i].cnt;j--)
            dp[j] = dp[j] + dp[j-v[i].cnt],dp[j]%=p;
    }
    //dp[od]
    if(dp[od] == 0)
    {
        cout<<"0\n";
        return ;
    }
    int de = 1;
    for(int i=0;i<26;i++)
    {
        if(c[i]>0)
            de = de*fac[c[i]]%p;
    }

    cout<<dp[od]%p*fac[od]%p*fac[ev]%p * qp(de,p-2)%p<<"\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    fac[0] = inv[0] = 1;
    for(int i=1;i<=5e5;i++)
        fac[i] = fac[i-1]*i%p,inv[i] = qp(fac[i],p-2);
    int t=1;
    cin>>t;
    while(t--)
        work();
}