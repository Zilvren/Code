#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n;cin>>n;
    int p = 1;
    int ans = 1;
    for(int i=2;i<=n;i++)
    {
        ans += p;
        if(i%2==1)
        p++;
    }
    cout<<ans<<"\n";
    // vector<int> a(n+1);

    // iota(a.begin(),a.end(),0);

    // set<int> S;

    // do
    // {
    //     int ans = 0;
    //     for(int i=1;i<=n;i++)
    //         ans += abs(a[i] - i);
    //     S.insert(ans);
    // }while(next_permutation(++a.begin(),a.end()));
    // cout<<S.size()<<"\n";

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