#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n;cin>>n;
    vector<array<int,2>> S;
    int sum = 0;
    for(int i=1;i<=n;i++)
    {
        int a;cin>>a;
        if(S.empty())
        {
            S.push_back({a,1}),sum=1;
            cout<<sum<<"\n";
            continue;
        }

        if(S.back()[0] == a)
        {
            if(S.back()[1] + 1 >= a)
            {
                sum -= S.back()[1];
                S.pop_back();
            }
            else
            {
                S.back()[1] ++;
                sum++;
            }
        }
        else
            S.push_back({a,1}),sum++;
        
        cout<<sum<<"\n";
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