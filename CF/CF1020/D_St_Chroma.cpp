#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,x;cin>>n>>x;
    vector<int> a(n+1);
    vector<bool> vis(n+1);
    for(int i=1;i<=x;i++)
        a[i] = i-1,vis[i-1] = 1;

    for(int i=x+1;i<n;i++)
        a[i] = i,vis[i] = 1;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
            a[n] = i;
    }

    for(int i=1;i<=n;i++)
        cout<<a[i]<<" \n"[i==n];
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