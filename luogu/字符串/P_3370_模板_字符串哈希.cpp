#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f

using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 1e5+7;
const int P = 131;
void work()
{
    int n;cin>>n;
    vector<int> p(n+1);
    p[0] = 1;
    for(int i=1;i<=n;i++)
        p[i] = p[i-1]*P;

    auto get_hash = [&](string s)
    {
        int n = s.size();
        s = '#' + s;
        vector<ull> h(n+1);

        for(int j=1;j<=n;j++)
            h[j] = h[j-1] *P + s[j];
        return h[n];
    };
    vector<int> h(n+1);
    for(int i=1;i<=n;i++)
    {
        string s;cin>>s;
        h[i] = get_hash(s);
    }
    set<ull> S;

    for(int i=1;i<=n;i++)
        S.insert(h[i]);
    cout<<S.size();
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