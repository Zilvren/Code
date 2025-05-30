#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,m;cin>>n;
    m = n;
    vector<vector<int>> g(n+1,vector<int>(m+1));

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>g[i][j];

    vector<int> row(n+1),col(m+1);

    for(int i=1;i<=n;i++)
        cin>>row[i];

    for(int i=1;i<=m;i++)
        cin>>col[i];

    vector<vector<int>> dpr(n+1,vector<int>(2,lnf)),dpc(m+1,vector<int>(2,lnf));
    dpr[1][0] = 0;
    dpr[1][1] = row[1];
    for(int i=2;i<=n;i++)
    {
        for(int x = 0;x<2;x++)
        for(int y = 0;y<2;y++)
        {
            bool f = 1;
            for(int j=1;j<=m;j++)
            {
                if(g[i][j] + x == g[i-1][j] + y)
                {
                    f = 0;
                    break;
                }
            }
            if(f)
            {
                if(x == 0)
                    dpr[i][x] = min(dpr[i][x],dpr[i-1][y]);
                else
                    dpr[i][x] = min(dpr[i][x],dpr[i-1][y] + row[i]);
            }
        }
    }
    dpc[1][0] = 0;
    dpc[1][1] = col[1];
    for(int i=2;i<=m;i++)
    {
        for(int x = 0;x<2;x++)
        for(int y = 0;y<2;y++)
        {
            bool f = 1;
            for(int j=1;j<=n;j++)
            {
                if(g[j][i] + x == g[j][i-1] + y)
                {
                    f = 0;
                    break;
                }
            }
            if(f)
            {
                if(x == 0)
                    dpc[i][x] = min(dpc[i][x],dpc[i-1][y]);
                else
                    dpc[i][x] = min(dpc[i][x],dpc[i-1][y] + col[i]);
            }
        }
    }
    if(min(dpc[m][0],dpc[m][1]) == lnf || min(dpr[n][0],dpr[n][1]) == lnf)
        cout<<-1<<"\n";
    else
        cout<<min(dpc[m][0],dpc[m][1]) + min(dpr[n][0],dpr[n][1])<<"\n";
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