#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n;cin>>n;
    string s;cin>>s;
    s = '#' + s;
    int ans =0;
    int cnt1 = count(s.begin(),s.end(), '1');
    for(int i=1;i<=n;i++)
    {
        if(s[i] == '1')
        {
            ans += cnt1 -1;
        }
        else
        {
            ans += cnt1+1;
        }
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