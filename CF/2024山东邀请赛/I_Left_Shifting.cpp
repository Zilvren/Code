#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    string s;cin>>s;
    int n = s.size();
    s = s+ s;
    s = '#' + s;
    // cout<<s<<"\n";
    for(int i=1;i<=n;i++)
    {
        if(s[i] == s[i+n-1])
        {
            cout<<i-1<<"\n";
            return ;
        }
    }
    cout<<-1<<"\n";
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