#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n;cin>>n;
    vector<array<int,3>> a(n+1);
    vector<int> sum(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][0];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][1];
        a[i][2] = a[i][0] + a[i][1];
        sum[i] = sum[i-1] + a[i][0];
    }
    int ans = 0;
    int st = 1;
    

    for(int i=2;i<=n;i++)
    {
        if(a[i][2] != a[i-1][2])
        {
            ans = max(ans,(i-st)*(sum[i-1]-sum[st-1]));
            st = i;
        }
    }
    ans = max(ans,(n-st+1)*(sum[n]-sum[st-1]));
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