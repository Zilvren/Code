#include<bits/stdc++.h>
//#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
vector<vector<int>> fac(N);
void get()
{
    for(int i=1;i<=1e5;i++)
        for(int j=i;j<=1e5;j+=i)
            fac[j].push_back(i);
}
void work()
{
    int n;cin>>n;
    int q;cin>>q;

    vector<int> a(n+1);

    map<int,vector<int>> mp;
    //vector<vector<int>> mp;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    vector<array<int,3>> query(q+1);
    for(int i=1;i<=q;i++)
    {
        cin>>query[i][0]>>query[i][1]>>query[i][2];
    }
    for(int i=1;i<=n;i++)
        mp[a[i]].push_back(i);
    for(int i=1;i<=q;i++)
    {
        auto [k,l,r] = query[i];
        vector<int> t;
        for(auto &a:fac[k])
        {
//            auto p =lower_bound(mp[a].begin(),mp[a].end(),l);
//            if(p!=mp[a].end()&&*p <= r)
//                t.push_back(*p);
            int p =lower_bound(mp[a].begin(),mp[a].end(),l) - mp[a].begin();
            if(p<mp[a].size())
            {
                int tt =mp[a][p];
                if(tt<=r)
                {
                    t.push_back(tt);
                }
            }

        }
        t.push_back(l);
        t.push_back(r+1);
        sort(t.begin(),t.end());

        ll ans =0 ;
        int kt = k;
        for(int j=1;j<t.size();j++)
        {
            if(j == 1)
            {
                ans += (ll)(t[j] - t[j-1]) * kt;
                continue;
            }
            while(kt%a[t[j-1]] == 0)
                kt/=a[t[j-1]];
            ans += (ll)(t[j] - t[j-1])*kt;

        }
        cout<<ans<<"\n";
    }

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    get();
    int t=1;
    cin>>t;
    while(t--)
        work();
}
/*
1
4 3
18 12 8 9
216 1 2
48 2 4
82944 1 4

1
4 2
18 12 8 9
48 2 4
82944 1 4
 */