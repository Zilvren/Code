#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = '#' + s;
    t = '#' + t;

    vector<int> z(m + 1);
    z[1] = m;
    for (int i = 2, l = 0, r = 0; i <= m; i++)
    {
        if (i <= r)z[i] = min(r - i + 1, z[i - l + 1]);
        while (t[i + z[i]] == t[z[i] + 1])z[i]++;
        if (i + z[i] - 1 > r)
        {
            r = i + z[i] - 1;
            l = i;
        }
    };

    vector<int> p(n + 1);
    for (int i = 1, l = 0, r = 0; i <= n; i++)
    {
        if (i <= r)
            p[i] = min(z[i - l + 1], r - i + 1);
        while (i + p[i] <= n && p[i] + 1 <= m && s[i + p[i]] == t[p[i] + 1])p[i]++;

        if (i + p[i] - 1 > r)
        {
            r = i + p[i] - 1;
            l = i;
        }
    };

    int ans1 = 0;
    for (int i = 1; i <= m; i++)
        ans1 ^= i * (z[i] + 1);
    int ans2 = 0;
    for (int i = 1; i <= n; i++)
        ans2 ^= i * (p[i] + 1);

    cout << ans1 << "\n" << ans2 << "\n";
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