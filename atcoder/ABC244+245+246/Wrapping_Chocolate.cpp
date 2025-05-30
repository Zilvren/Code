#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,m;cin>>n>>m;
    vector<array<int,3>> a(n+m+1);

    for(int i=1;i<=n;i++)
        cin>>a[i][0],a[i][2] = 0;

    for(int i=1;i<=n;i++)
        cin>>a[i][1],a[i][2] = 0;

    for(int i=n+1;i<=n+m;i++)
        cin>>a[i][0],a[i][2] = 1;

    for(int i=n+1;i<=n+m;i++)
        cin>>a[i][1],a[i][2] = 1;

    sort(++a.begin(),a.end(),[](array<int,3> a,array<int,3> b)
    {
        if(a[0] == b[0])
            return a[2]<b[2];
        return a[0]<b[0];
    });
    multiset<int> S;
    S.insert(-lnf);
    for(int i=1;i<=n+m;i++)
    {
        if(a[i][2] == 1)
        {
            auto p = S.upper_bound(a[i][1]);
            p--;
            if(p == S.begin())
                continue;
            
            S.erase(p);
        }
        else
        {
            S.insert(a[i][1]);
        }
    }
    if(S.size()==1)
        cout<<"Yes\n";
    else
        cout<<"No\n";

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