#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,x;cin>>n>>x;
    if(x == 1)
    {
        if(n%2==1)
            cout<<n<<"\n";
        else
            cout<<n-2 + 5<<"\n";
        return ;
    }
    if(x == 0)
    {
        if(n==1)
        {
            cout<<-1<<"\n";
            return ;
        }
        if(n%2==0)
        {
            cout<<n<<"\n";
        }
        else
        {
            cout<<n-2+5<<"\n";
        }
        return ;
    }
    int cnt0 = __builtin_popcount(x);
    if(cnt0 >= n)
    {
        cout<<x<<"\n";
        return ;
    }
    if((n-cnt0)%2==0)
    {
        cout<<x + n - cnt0<<"\n";
    }
    else
    {
        cout<<x + n - cnt0 + 1<<"\n";
    }

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