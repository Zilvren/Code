#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int a,b,c;cin>>a>>b>>c;
    if((a+b+c)%3==0&&b <= (a+b+c)/3)
    {
        cout<<"YES\n";
    }
    else
        cout<<"NO\n";
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