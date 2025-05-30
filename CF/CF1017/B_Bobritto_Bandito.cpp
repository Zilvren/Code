#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,m,l,r;cin>>n>>m>>l>>r;
    if(m<=r)
    {
        cout<<0<<" "<<m<<"\n";
    }
    else
    {
        cout<<-(m-r)<<" "<<r<<"\n";
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