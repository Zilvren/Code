#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    string s;cin>>s;
    int q;cin>>q;
    s = '#' + s;
    function<int(int,int)> dfs = [&](int t,int k) -> int
    {
        if(t == 0)
            return (s[k] - 'A')%3;
        if(k == 1)
            return ((s[k] - 'A') + t%3)%3;
        
        if(k%2==0)
            return (dfs(t-1,k/2)+2)%3;
        else
            return (dfs(t-1,(k+1)/2)+1)%3;
    };
    while(q--)
    {
        int t,k;cin>>t>>k;
        cout<<char(dfs(t,k) + 'A')<<"\n";
    }
}

signed main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(0),cout.tie(0);

    // int t=1;
    // cin>>t;
    // while(t--)
        work();
}