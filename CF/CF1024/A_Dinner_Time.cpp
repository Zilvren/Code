#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,m,p,q;
    cin>>n>>m>>p>>q;
    if(n%p==0)
    {
        if(m == n/p * q)
        {
            cout<<"YES\n";
        }
        else
            cout<<"NO\n";
    }
    else
    {
        cout<<"YES\n";
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