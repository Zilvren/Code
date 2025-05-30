#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n;cin>>n;
    vector<vector<int>> g(n+2,vector<int> (n+2,-1));
    int x = 1,y = 1;
    int p = n*n-1;
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            g[i][j] = 0;
    int d = 0;
    while(p != 0)
    {
        g[x][y] = p;
        int nx = x+ dx[d],ny = y+ dy[d];
        while(g[nx][ny] != 0)
        {
            d = (d+1)%4;
            nx = x+ dx[d],ny = y+ dy[d];
        }
        x = nx,y = ny;
        p--;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cout<<g[i][j]<<" \n"[j==n];
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