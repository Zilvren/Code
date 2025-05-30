#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    string a,s;cin>>a>>s;

    vector<pair<char,int>> gs,ga;
    int cnt = 1;
    for(int i=1;i<s.size();i++)
    {
        if(s[i] != s[i-1])
        {
            gs.push_back({s[i-1],cnt});
            cnt = 1;
        }
        else
            cnt++;
    }
    gs.push_back({s.back(),cnt});

    cnt = 1;
    for(int i=1;i<a.size();i++)
    {
        if(a[i] != a[i-1])
        {
            ga.push_back({a[i-1],cnt});
            cnt = 1;
        }
        else
            cnt++;
    }
    ga.push_back({a.back(),cnt});
    if(ga.size()!=gs.size())
    {
        cout<<"NO\n";
        return ;
    }
    for(int i=0;i<ga.size();i++)
    {
        if(ga[i].second<=gs[i].second&&gs[i].second<=ga[i].second*2)
        continue;
        else
        {
            cout<<"NO\n";
            return ;
        }
    }
    cout<<"YES\n";
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