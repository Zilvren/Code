#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int q;cin>>q;
    deque<array<int,2>> Q;

    while(q--)
    {
        int op;cin>>op;
        if(op == 1)
        {
            int x,c;cin>>x>>c;
            Q.push_back({x,c});
        }
        else
        {
            int C;cin>>C;
            int sum = 0;
            while(C)
            {
                auto [x,c] = Q.front();
                Q.pop_front();
                if(C - c > 0)
                {
                    C -= c;
                    sum += x*c;
                }
                else
                {
                    sum += C*x;
                    Q.push_front({x,c - C});
                    C = 0;
                }
            }
            cout<<sum<<"\n";
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