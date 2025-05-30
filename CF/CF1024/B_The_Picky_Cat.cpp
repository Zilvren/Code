#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    auto check = [&]()
    {
        int l = 0, r = 0;
        int cl = 0, cr = 0;
        for (int i = 2; i <= n; i++)
        {
            if (a[i] >= a[1])
            {
                r++;
                if(abs(a[i]) > abs(a[1]))
                    cr++;
            }
            else if (a[i] < a[1])
            {
                l++;
                if(abs(a[i]) > abs(a[1]))
                    cl++;
            }
        }
        if (n % 2 == 1)
        {
            if (l > r)
            {
                if (l - r <= cl * 2)
                {
                    cout << "YES\n";
                    return true;
                }
            }
            else if (r == l)
            {
                cout << "YES\n";
                return true;
            }
            else if (r > l)
            {
                if (abs(l - r) <= cr * 2)
                {
                    cout << "YES\n";
                    return true;
                }
            }
        }
        else
        {
            if (l + 1 > r)
            {
                if (abs((l + 1) - r)<= cl * 2)
                {
                    cout << "YES\n";
                    return true;
                }
            }
            else if (r == l + 1)
            {
                cout << "YES\n";
                return true;
            }
            else if (r > l + 1)
            {
                if (abs((l + 1) - r) <= cr * 2)
                {
                    cout << "YES\n";
                    return true;
                }
            }
        }
        return false;
    };
    a[1] = abs(a[1]);
    if(check())
    {
        return ;
    }

    a[1] = -a[1];
    if(check())
        return ;
    cout<<"NO\n";
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