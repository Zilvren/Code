#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];

    vector<int> suf(n+2);

    for(int i=n;i>=1;i--)
        suf[i] = suf[i+1] + a[i];
    int ans = suf[1];
    sort(suf.begin()+2,--suf.end(),greater<int>());

    cout<<ans<<" ";
    for(int i=2;i<=n;i++)
    {
        ans += suf[i];
        cout<<ans<<" ";
    }
    cout<<"\n";

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