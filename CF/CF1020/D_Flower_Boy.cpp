#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,m;cin>>n>>m;
    vector<int> a(n+1);
    vector<int> b(m+1);

    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=1;i<=m;i++)
        cin>>b[i];

    int ls = 0;
    int p = 1;
    for(int i=1;i<=n;i++)
    {
        if(a[i] >= b[p])
        {
            p++;
            if(p>m)
            {
                cout<<0<<"\n";
                return ;
            }
            ls = i;
        }
    }
    p++;
    int ans = b[p];
    for(int i = ls + 1;i<=n;i++)
    {
        if(a[i]<b[p])
        {
            cout<<-1<<"\n";
            return ;
        }
        else
            p++;
    }
    cout<<ans<<"\n";
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