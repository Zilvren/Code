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
    int sum =0 ;
    for(int i=1;i<=n;i++)
        cin>>a[i],sum+=a[i];

    priority_queue<int,vector<int>,greater<int>> Q;
    for(int i=1;i<=n;i++)
    {
        Q.push(a[i]);
    }
    if(sum != m)
        Q.push({m - sum});
    
    int ans = 0;
    while(Q.size()>1)
    {
        int a = Q.top();
        Q.pop();
        int b = Q.top();
        Q.pop();
        ans += a+b;
        // cout<<a<<' '<<b<<"\n";
        Q.push(a+b);
    } 
    cout<<ans<<"\n";
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