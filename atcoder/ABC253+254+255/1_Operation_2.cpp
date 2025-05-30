#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,q;cin>>n>>q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];

    sort(++a.begin(),a.end());
    vector<int> s(n+1);
    for(int i=1;i<=n;i++)
    {
        s[i] = s[i-1] + a[i];
    }
    while(q--)
    {
        int x;cin>>x;

        int p = lower_bound(++a.begin(),a.end(),x) - a.begin();
        cout<<(s[n] - s[p-1])-x*(n-p+1) + x *(p-1) - s[p-1]<<"\n";
    }
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