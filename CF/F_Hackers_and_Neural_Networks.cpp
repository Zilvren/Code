#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
struct Node
{
    vector<string> s;
    int c;
    Node(int n):s(n+1){}
};
void work()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<Node> g(m + 1, Node(n + 1));

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> g[i].s[j];
        }

    vector<bool> vis(n + 1);
    int cnt =0 ;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && a[j] == g[i].s[j])
                vis[j] = 1,cnt++;
        }
    }
    if(cnt !=n)
    {
        cout<<-1<<"\n";
        return ;
    }
    for(int i=1;i<=n;i++)
        vis[i] = 0;
    for (int i = 1; i <= m; i++)
    {
        g[i].c = 0;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && a[j] == g[i].s[j])
                g[i].c++;
        }
    }
    int ans = 0;
    int rel = 0;
    int f = -1;

    int t = 0;
    cnt = 0;
    sort(++g.begin(), g.end(), [&](Node a, Node b)
    {
        return a.c > b.c;
    });

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            t++;
        }
        if (!vis[i] && a[i] == g[1].s[i])
        {
            vis[i] = 1;
            cnt++;
        }
    }
    ans += t;
    if (f == -1)
        f = t - cnt;
    if (f != -1)
        ans += f*2;

    cout << ans<< "\n";
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