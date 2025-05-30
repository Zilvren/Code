#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
const int p = 1000000007;
int fac[N],inv[N];
int qp(int a,int b)
{
    int ans = 1;
    while(b)
    {
        if(b&1)
            ans = ans*a,ans%=p;
        a = a*a,a%=p;
        b>>=1;
    }
    return ans;
}
int C(int n,int m)
{
    if(m>n)return 0;
    return fac[n] * inv[m]%p * inv[n-m]%p;
}
void work()
{
    int n;cin>>n;

    vector<int> de(n+1);
    map<int,int>mp;
    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        de[u]++;
        de[v]++;
    }
    for(int i=1;i<=n;i++)
        mp[de[i]]++;
    int l,r;cin>>l>>r;
    int ans = 0;
    for(auto &t:mp)
    {
        for(int i=l;i<=r;i++)
        {
            ans += C(t.first,i-1)*t.second%p;
            ans %= p;
        }
    }
    cout<<ans;

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    fac[0] = inv[0] = 1;
    for(int i=1;i<=1e5;i++)
        fac[i] = fac[i-1] * i%p,inv[i] = qp(fac[i],p-2);
    // int t=1;
    // cin>>t;
    // while(t--)
        work();
}