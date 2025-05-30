#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
struct Node
{
    int l,r,w;
};
void work()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '#' + s;
    Node u = {}, d = {};
    array<int, 2> p = {0, 0};
    int ans = 0;
    if (s[1] == '1')
    {
        p[0] = 1;
        p[1] = 1;
    }
    else
    {
        u.l = 0;
        u.r = 0;
        d.l = 2;
        d.r = n;
        d.w = d.r - d.l + 1;
    }
    ans = max({p[1],d.w,u.w});
    for (int i = 2; i <= n; i++)
    {
        if (s[i] == '1')
        {
            p[1] = 1;
            p[0] = i;
            if(s[i-1] == '0')
            {
                if (u.l <= p[0] && p[0] <= u.r)
                    p[1] += u.w;
                else if (d.l <= p[0] && p[0] <= d.r)
                    p[1] += d.w;
            }
            d = {};
            u = {};
            ans = max(ans, p[1]);
        }
        else
        {
            if (s[i - 1] == '1')
            {
                u.l = 1, u.r = i - 1;
                d.l = i + 1, d.r = n;
                d.w = d.r - d.l + 1;
                u.w = u.r - u.l + 1;
                if (u.l <= p[0] && p[0] <= u.r)
                    u.w += p[1];
                else if (d.l <= p[0] && p[0] <= d.r)
                    d.w += p[1];

            }
            else
            {
                int l = 1, r = i - 1;
                int uw = r - l + 1;
                if (!(l > u.r || r < u.l))
                    uw += u.w;
                if (!(l > d.r || r < d.l))
                    uw += d.w;

                l = i + 1, r = n;
                int dw = r - l + 1;
                if (!(l > u.r || r < u.l))
                    dw += u.w;

                if (!(l > d.r || r < d.l))
                    dw += d.w;
                u.l = 1, u.r = i - 1;
                d.l = i + 1, d.r = n;
                u.w = uw, d.w = dw;
            }
            p = {};
            ans = max({ans, d.w, u.w});
        }
    }
    cout << ans << "\n";
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