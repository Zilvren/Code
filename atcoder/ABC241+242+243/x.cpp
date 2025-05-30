#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
const int p = 998244353;
void work()
{
    string s;
    int n;cin>>n>>s;
    int m = s.size();
    s = '#' + s;

    int ans = 0;
    for(int i=1;i<=(n+1)/2;i++)
    {
        ans = ans * 26%p + (s[i] - 'A'),ans%=p;
    }
    string f = s.substr(1,(n+1)/2);
    string b = s.substr(1,n/2);
    reverse(b.begin(),b.end());
    // cout<<f+b<<"\n";
    if(f+b<=s.substr(1))
        ans++;
    cout<<ans%p<<"\n";
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