#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,k;cin>>n>>k;

    vector<array<int,2>> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i][0];

    for(int i=1;i<=n;i++)
        cin>>a[i][1];

    sort(++a.begin(),a.end(),[&](array<int,2> a,array<int,2> b)
    {
        return min(a[0],a[1])>min(b[0],b[1]);
    });

    int ans =0 ;
    for(int i=1;i<=n;i++)
        ans += max(a[i][1],a[i][0]);

    for(int i=1;i<k;i++)
        ans += min(a[i][1],a[i][0]);
    cout<<ans+1<<"\n";
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