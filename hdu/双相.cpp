#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n;cin>>n;
    vector<array<int,2>> v(n+1);

    for(int i=1;i<=n;i++)
        cin>>v[i][0];
    for(int i=1;i<=n;i++)
    {
        char c;cin>>c;
        if(c == 'B')
            v[i][1] = 0;
        else
            v[i][1] = 1;
    }

    vector<int> b,r;
    for(int i=1;i<=n;i++)
    {
        if(v[i][1] == 0)
            b.push_back(v[i][0]);
        else
            r.push_back(v[i][0]);
    }
     b.push_back(0);
    sort(r.begin(),r.end(),greater<int>());
    sort(b.begin(),b.end(),greater<int>());
    int ans =0 ;
    for(int i=0;i<r.size()&&i<b.size();i++)
        ans += r[i]+b[i];
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