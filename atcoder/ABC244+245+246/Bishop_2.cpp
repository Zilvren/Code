#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
struct Node
{
    int x,y,s;
    bool operator<(Node t)const
    {
        return s>t.s;
    }
};
void work()
{
    int n;cin>>n;
    vector<vector<char>> g(n+1,vector<char>(n+1));
    int sx,sy;cin>>sx>>sy;
    int ex,ey;cin>>ex>>ey;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>g[i][j];

    vector<vector<int>> dist(n+1,vector<int>(n+1,lnf));
    vector<vector<bool>> vis(n+1,vector<bool>(n+1));

    auto dijskra = [&]()
    {
        priority_queue<Node> Q;
        Q.push({sx,sy,0});
        dist[sx][sy] = 0;
        while(Q.size())
        {
            auto [x,y,s] = Q.top();
            Q.pop();
            if(vis[x][y])continue;
            vis[x][y] = 1;
            int dx[] = {-1,1,-1,1};
            int dy[] = {1,-1,-1,1};
            for(int i=0;i<4;i++)
            {
                int nx = x + dx[i],ny = y + dy[i];
                while(1<=nx&&nx<=n&&1<=ny&&ny<=n&&g[nx][ny] == '.')
                {
                    if(dist[nx][ny] >= dist[x][y] + 1)
                    {
                        dist[nx][ny] =  dist[x][y] + 1;
                        Q.push({nx,ny,dist[nx][ny]});
                        nx += dx[i];
                        ny += dy[i];
                    }
                    else
                        break;
                }
            }
        }
    };

    dijskra();
    if(dist[ex][ey] == lnf)
        cout<<-1;
    else
        cout<<dist[ex][ey];
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