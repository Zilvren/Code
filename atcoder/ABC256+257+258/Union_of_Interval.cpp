#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n;cin>>n;
    vector<array<int,2>> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i][0]>>a[i][1];

    sort(++a.begin(),a.end());

    auto [L,R] = a[1];
    vector<array<int,2>> ans;
    for(int i=2;i<=n;i++)
    {
        auto [l,r] = a[i];
        if(l<=R)
        {
            R = max(R,r);
        }
        else
        {
            ans.push_back({L,R});
            L = l,R = r;
        }
    }
    ans.push_back({L,R});
    for(auto [l,r]:ans)
        cout<<l<<" "<<r<<"\n";
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