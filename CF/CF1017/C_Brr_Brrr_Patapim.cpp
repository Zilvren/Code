#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n;cin>>n;
    vector<vector<int>> g(n+1,vector<int>(n+1));

    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
        cin>>g[i][j];

    vector<int> ans(2*n+1);
    int sum = 2*n*(2*n+1)/2;
    for(int i=1;i<=n;i++)
    {
        ans[i+1] = g[1][i];
        sum -= ans[i+1];
    }
    for(int i=2;i<=n;i++)
    {
        ans[i+n] = g[i][n];
        sum -= ans[i+n];
    }
    for(int i=1;i<=2*n;i++)
    {
        if(ans[i] == 0)
            cout<<sum<<" ";
        else
            cout<<ans[i]<<" ";
    }
    cout<<"\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t=1;
    cin>>t;
    while(t--)
        work();
}