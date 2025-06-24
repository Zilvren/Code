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
    string s;
    cin >> s;
    s = '#' + s;
    s += 'z' + 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] > s[i + 1])
        {
            for (int j = 1; j < i; j++)
                cout << s[j];
            for (int j = i + 1; j <= n + 1; j++)
            {
                if (s[j] > s[i])
                {
                    for (int z = i + 1; z < j; z++)
                        cout << s[z];
                    cout << s[i];
                    for (int z = j; z <= n; z++)
                        cout << s[z];
                    cout << "\n";
                    return;
                }
            }
        }
    }
    cout << s.substr(1,n) << "\n";

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