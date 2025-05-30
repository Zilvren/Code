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
    g[1][1] = 1;
    g[1][n] = 2;
    g[n][1] = 3;
    g[n][n] = 4;
    int p = 5;
    for(int i=2;i<=n-1;i++)
        g[1][i] = p++;
    for(int i=2;i<=n-1;i++)
        g[i][1] = p++;
    
    
    for(int i=2;i<n;i++)
        for(int j=1;j<=n;j++)
        {
            g[i][j] = g[i][1];
        }
    for(int i=2;i<n;i++)
        g[n][i] = g[1][i];
    cout<<"Yes\n";
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cout<<g[i][j]<<" \n"[j==n];
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