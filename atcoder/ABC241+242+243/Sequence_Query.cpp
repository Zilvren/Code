#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int q;cin>>q;
    multiset<int> S;
    S.insert(-lnf);
    S.insert(lnf);
    S.insert(lnf);
    for(int i=1;i<=q;i++)
    {
        int op;cin>>op;
        if(op == 1)
        {
            int x;cin>>x;
            S.insert(x);
        }
        else if(op == 2)
        {
            int x,k;cin>>x>>k;
            auto p = S.upper_bound(x);
            for(int j=1;j<=k;j++)
            {
                --p;
                if(p == S.begin())
                    break;
            }
            cout<<((*p == -lnf)?-1:*p)<<"\n";
        }
        else
        {
            int x,k;cin>>x>>k;
            auto p = S.lower_bound(x);
            for(int j=1;j<k;j++)
            {
                ++p;
                if(p == (--S.end()))
                    break;
            }
            cout<<((*p==lnf)?-1:*p)<<"\n";
        }
    }
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