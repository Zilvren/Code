#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
struct Node
{
    int x,y;
    int s;
    bool operator<(Node t) const
    {
        return s>t.s;
    }
};
void work()
{
    int n,m;cin>>n>>m;

    vector<vector<int>> g(n+1,vector<int>(m+1));
    vector<vector<bool>> vis(n+1,vector<bool>(m+1));
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
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
    int stx,sty,edx,edy;
    cin>>stx>>sty>>edx>>edy;

    priority_queue<Node> Q;

    Q.push({stx,sty,0});
    while(Q.size())
    {
        auto [x,y,s] = Q.top();
        Q.pop();
        if(vis[x][y])
        continue;
        vis[x][y] = 1;
        if(x == edx&&y == edy)
        {
            cout<<s<<"\n";
            return ;
        }
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nx2 = x + dx[i]*2;
            int ny2 = y + dy[i]*2;
            if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&g[nx][ny])
            {
                Q.push({nx,ny,s});
            }
            else if((1<=nx&&nx<=n&&1<=ny&&ny<=m&&!g[nx][ny]))
            {
                Q.push({nx,ny,s+1});
            }
            if((1<=nx2&&nx2<=n&&1<=ny2&&ny2<=m&&!g[nx2][ny2]))
            {
                Q.push({nx2,ny2,s+1});
            }

        }
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