#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
bool is_primes(int x)
{
    if(x<2)
    return false;

    for(int i=2;i<=x/i;i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}
void work()
{
    int n,k;cin>>n>>k;
    if(k==1)
    {
        if(is_primes(n))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    else
    {
        if(n>=10)
        {
            cout<<"NO\n";
        }
        else
        {
            if(k==2&&n==1)
            {
                cout<<"YES\n";
            }
            else
                cout<<"NO\n";
        }
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