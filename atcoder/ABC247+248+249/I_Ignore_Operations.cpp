#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,k;cin>>n>>k;
    vector<array<int,2>> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
    multiset<int,greater<int>> S;

//    S.insert(-200);
//    S.insert(-100);
//    cout<<*S.begin();
    int sum = 0;
    int ans = -lnf;
    a[0] = {1,0};
    for(int i=n;i>=0;i--)
    {
        auto [op,y] = a[i];
        if(op == 1)
        {
            ans = max(ans,y + sum);
            if(k>0)
            {
                k--;
            }
            else
            {
                if(S.size() == 0)
                {
                    break;
                }
                sum += *S.begin();
                S.erase(S.begin());
            }
        }
        else
        {
            if(y>0)
            {
                sum += y;
            }
            else
            {
                if(k > 0)
                {
                    k--;
                    S.insert(y);
                }
                else
                {
                    S.insert(y);
                    sum += *S.begin();
                    S.erase(S.begin());
                }
            }
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