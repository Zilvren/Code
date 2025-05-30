#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,k;cin>>n>>k;
    vector<array<int,2>> p(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>p[i][0]>>p[i][1];
    }

    if(k == 1)
    {
        cout<<"Infinity\n";
        return ;
    }
    //y = kx +b;
    //
    int ans =0 ;
    set<pair<int,int>> S;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            if(S.count({i,j}))continue;
            auto [x1,y1] = p[i];
            auto [x2,y2] = p[j];

            int cnt =0;
            vector<int> v;
            for(int z = 1;z<=n;z++)
            {
                auto [x3,y3] = p[z];
                if(y3*(x2-x1) == x3*(y2-y1) + y1*(x2-x1) - (y2-y1) *x1)
                {
                    cnt++;
                    v.push_back(z);
                }
            }

            for(int z=0;z<v.size();z++)
                for(int z2=0;z2<v.size();z2++)
                {
                    if(z == z2)continue;
                    S.insert({min(v[z2],v[z]),max(v[z2],v[z])});
                }

            if(cnt >=k)
                ans ++;
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