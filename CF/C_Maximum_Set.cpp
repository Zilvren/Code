#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e6+7;
const int p = 998244353;
int lg[N];

void work()
{
    int l,r;cin>>l>>r;

    int cnt = lg[r/l];
    int ans = r/(1<<cnt) - l + 1;
    ans %= p;
    ans += max((r/(1<<(cnt-1))/3 - l + 1),(ll)0)%p*cnt%p;

    cout<<cnt+1<<" "<<ans<<"\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    lg[1] = 0;
    for(int i=2;i<=1e6;i++)
        lg[i] = lg[i/2] + 1;

    int t=1;
    cin>>t;
    while(t--)
        work();
}