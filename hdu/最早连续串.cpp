#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    string s;cin>>s;
    int n= s.size();
    s = '#' + s;
    vector<int> sm(n+1);

    for(int i=1;i<=n;i++)
        sm[i] = sm[i-1] + ((s[i] == '1')?1:-1);

    for(int i=1;i<=n;i++)
        cout<<sm[i]<<" \n"[i==n];
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