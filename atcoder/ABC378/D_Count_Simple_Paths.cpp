#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
struct Node
{
    int x,y,s;
};
void work()
{
    int n,m;cin>>n>>m;
    int k;cin>>k;

    vector<vector<int>> g(n+1,vector<int>(m+1));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char c;cin>>c;
            if(c == '.')
                g[i][j] = 1;
            else
                g[i][j] = 0;
        }
    }

    vector<vector<vector<int>>> f(n+1,vector<vector<int>>(m+1,vector<int>(k+1)));
    vector<vector<bool>> vis(n+1,vector<bool>(m+1));
    function<void(int,int,int)> dfs=  [&](int x,int y,int s)
    {
        if(s == k)
        {
            f[x][y][s] ++;
            return ;
        }

        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i],ny = y+dy[i];
            if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&g[nx][ny]&&!vis[nx][ny])
            {
                vis[nx][ny] = 1;
                dfs(nx,ny,s+1);
                vis[nx][ny] = 0;
            }
        }

    };

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(g[i][j])
            {
                vis.assign(n+1,vector<bool>(m+1));
                vis[i][j] =1;
                dfs(i,j,0);
            }
        }
    int ans =0 ;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ans+=f[i][j][k];
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