#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    while (q--)
    {
        string op;
        cin >> op;
        if (op == "->")
        {
            int x, y;
            cin >> x >> y;
            x--; 
            y--;
            int num = 1;
            for (int i = 0; i < n; ++i)
            {
                int pos = n - 1 - i;
                int m = (ll) 1 << pos;
                int xb = (x & m) ? 1 : 0;
                int yb = (y & m) ? 1 : 0;
                if (!xb&&!yb)
                {
                    continue;
                }
                else if (xb&&yb)
                {
                    num += m*m;
                }
                else if (xb&&!yb)
                {
                    num += 2*m*m;
                }
                else
                {
                    num += 3*m*m;
                }
            }
            cout << num << '\n';
        }
        else
        {
            int d;
            cin >> d;
            d--; 
            int x = 0, y = 0;
            for (int i = 0; i < n; ++i)
            {
                int s = 2 * (n - 1 - i);
                int w = (ll) 1 << s;
                int k = d / w;
                d %= w;
                int pos = n - 1 - i;
                int m = (ll) 1 << pos;
                if(k == 0)
                    continue;
                else if( k== 1)
                {
                    x |= m;
                    y |= m;
                }
                else if(k == 2)
                {
                    x |= m;
                }
                else
                {
                    y |= m;
                }
            }
            cout << x + 1 << ' ' << y + 1 << '\n';
        }


    }
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