#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,k;cin>>n>>k;
    vector<array<int,2>> a(n+1);
    vector<int> pre(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][0]>>a[i][1];
        pre[i] = pre[i-1] + a[i][0] + a[i][1];
    }


    int Min = lnf;
    int ans = lnf;
    for(int i=1;i<=n;i++)
    {
        Min = min(Min,a[i][1]);
        ans = min(ans,pre[i] +(k-i)*Min);
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