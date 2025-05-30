#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,q;cin>>n>>q;
    vector<int> a(n+1);

    for(int i=1;i<=n;i++)
        cin>>a[i];

    vector<int> lg(n+1);

    for(int i=2;i<=n;i++)
        lg[i] = lg[i/2] + 1;
    vector<vector<int>> st(n+1,vector<int> (lg[n]+1));
    for(int i=1;i<=n;i++)
        st[i][0] = a[i];
    for(int len = 1;len <= lg[n];len++)
    for(int l=1;l+(1<<(len-1))<=n;l++)
        st[l][len] = max(st[l][len-1],st[l+(1<<(len-1))][len-1]);
    auto Max = [&](int l,int r)
    {
        int len = lg[r-l+1];
        return max(st[l][len],st[r-(1<<(len))+1][len]);
    };
    while(q--)
    {
        int l,r;cin>>l>>r;
        cout<<Max(l,r)<<"\n";
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