#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,m;cin>>n>>m;
    //2 2 -3 4
    //2 4 1 5
    //2 6 7 12
    //-2 1
    //-2 -1
    //-2 -3

    //5 3 1
    //4 4 -1
    //
    vector<array<int,2>> a(n+2);

    for(int i=1;i<=n;i++)
    {
        int x,c;cin>>x>>c;
        a[i] = {x,c};
    }
    a[n+1] = {-lnf,1};
    vector<int> s1(n+2),s2(n+2);
    int l = 1;
    vector<array<int,3>> R;
    for(int i=1;i<=n+1;i++)
    {
        s1[i] = s1[i-1] + a[i][0]*a[i][1];
        s2[i] = s2[i-1] + a[i][0]*((l + l+a[i][1]-1)*(a[i][1])/2);

        if(a[i][0]<0&&s1[i]<=0&&s1[i-1]>0)
        {
            R.push_back({s1[i-1]/(-a[i][0])+l-1,l,i});
        }
        l += a[i][1];
    }
    int ans = -lnf;
    for(auto [r,l,i]:R)
    {
        int x = (r+1)*(s1[i-1]+(r-l+1)*a[i][0]),y = (s2[i-1] + (l+r)*(r-l+1)/2*a[i][0]);
        ans = max(ans,(r+1)*(s1[i-1]+(r-l+1)*a[i][0]) - (s2[i-1] + (l+r)*(r-l+1)/2*a[i][0]));
    }
    ans = max(ans,a[1][0]);
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