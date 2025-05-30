#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,a,b,c;cin>>n>>a>>b>>c;

    int ans = n;

    if(n>=a+b+c)
    {
        ans = n-a-b-c;
    }
    if(n>=a+b)
    {
        ans = min(n-a-b,ans);
    }
    if(n>=b+c)
        ans = min(ans,n-c-b);
    if(n>=a+c)
        ans = min(ans,n-a-c);

    if(n>=a)
        ans = min(ans,n-a);
    if(n>=b)
        ans = min(ans,n-b);
    if(n>=c)
        ans = min(ans,n-c);
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