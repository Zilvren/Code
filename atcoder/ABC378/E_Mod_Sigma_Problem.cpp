#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,m;cin>>n>>m;
    vector<int>a(n+1);
    vector<int> s(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i],s[i] = (s[i-1]%m + a[i]%m)%m;
    vector<int> ss(n+1);
    for(int i=1;i<=n;i++)
        ss[i] = ss[i-1] + s[i];
    vector<int> tr(m+1);

    auto update = [&](int x,int d)
    {
        for(int i=x;i<=m;i+=(i&-i))
            tr[i] += d;
        return ;
    };
    auto getSum = [&](int x)
    {
        int ans = 0;
        for(int i=x;i>=1;i -= (i&-i))
            ans += tr[i];
        return ans;
    };

    int ans =0 ;
    for(int i=1;i<=n;i++)
    {
        ans += (i*s[i] - ss[i-1] + m*(getSum(m)-getSum(s[i]+1)));
        update(s[i]+1,1);
//        for(int j=0;j<m;j++)
//            cout<<getSum(j) - getSum(j-1)<<" \n"[j==m-1];
    }
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