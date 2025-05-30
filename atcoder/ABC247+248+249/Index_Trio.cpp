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
    map<int,int> mp;
    for(int i=1;i<=n;i++)
        cin>>a[i],mp[a[i]]++;
    sort(++a.begin(),a.end());
    a.erase(unique(++a.begin(),a.end()),a.end());
    int ans = 0;
    for(int i=1;i<a.size();i++)
    {
        if(a[i] == 1)continue;
        for(int j=2;j<=a[i]/j;j++)
        {
            if(a[i]%j == 0)
            {
                if(j!=a[i]/j)
                    ans += mp[j]*mp[a[i]/j]*2*mp[a[i]];
                else 
                    ans += mp[j]*mp[j]*mp[a[i]];
            }
        }
    }

    ans += mp[1] *mp[1]*mp[1];
    for(int i=1;i<a.size();i++)
    {
        if(a[i] != 1)
        {
            ans += mp[a[i]]*mp[a[i]] * mp[1]*2;
        }
    }
    cout<<ans<<"\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    // int t=1;
    // cin>>t;
    // while(t--)
    work();
}