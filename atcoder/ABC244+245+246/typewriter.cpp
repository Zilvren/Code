#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
const int p = 998244353;
int qp(int a,int b)
{
    int ans = 1;
    while(b)
    {
        if(b&1)
            ans *=a,ans %= p;
        a *=a,a%=p;
        b>>=1;
    }
    return ans;
}
void work()
{
    int n,l;cin>>n>>l;
    vector<string> g(n+1);
    vector<int>w(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>g[i];
        for(auto &c:g[i])
            w[i] |= 1<<(c - 'a');
    }
    int ans = 0;
    for(int i=1;i<(1<<n);i++)
    {
        int cnt= (1<<31)-1;
        for(int j=1;j<=n;j++)
        {
            if(i&(1<<(j-1)))
            {
                cnt &= w[j];
            }
        }
        if(__builtin_popcount(i)%2==0)
        {
            ans = (ans - qp(__builtin_popcount(cnt),l) + p)%p;
        }
        else
        {
            ans += qp(__builtin_popcount(cnt),l);
            ans %=p;
        }
    }
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