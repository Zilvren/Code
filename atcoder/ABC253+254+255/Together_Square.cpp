#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 2e5+7;

void work()
{
    int n;cin>>n;
    vector<int> f(n+1);
    iota(f.begin(),f.end(),0);
    for(int i=2;i<=n;i++)
        for(int j=i;j<=n;j+=i)
        {
            while(f[j]%(i*i) == 0)
                f[j] /= (i*i);
        }

    
    map<int,int> mp;
    for(int i=1;i<=n;i++)
    {
        mp[f[i]] ++;
    }
    int ans = 0;
    for(auto &[t,c]:mp)
    {
        ans += c*c;
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