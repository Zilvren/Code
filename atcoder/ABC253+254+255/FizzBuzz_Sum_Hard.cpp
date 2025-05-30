#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,a,b;cin>>n>>a>>b;
    int c = a*b/__gcd(a,b);
    cout<<(1+n)*n/2 - (a + n/a * a)*(n/a)/2 - (b + n/b * b)*(n/b)/2 + (c + n/c * c)*(n/c)/2;
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