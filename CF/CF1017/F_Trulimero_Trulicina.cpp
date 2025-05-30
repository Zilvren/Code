#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    //
    //1 3
    //3 2
    //2 1

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n + 1, vector<int>(m + 1));

    if(m%k !=0)
    {
        int p = 1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                g[i][j] = (p-1)%k+1;
                p++;
            }
    }
    else
    {
        int p = 1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                g[i][j] = (p-1)%k+1;
                p++;
            }

        for(int i=2;i<=n;i+=2)
        {
            int bk = g[i][m];
            for(int j=m;j>=2;j--)
                g[i][j] = g[i][j-1];
            g[i][1] = bk;
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cout << g[i][j] << " \n"[j == m];

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