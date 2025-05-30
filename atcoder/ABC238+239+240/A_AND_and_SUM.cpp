#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int a,s;cin>>a>>s;
    if(s < 2*a)
    {
        cout<<"No\n";
        return ;
    }
    // x and y  = a
    // x + y = s
    // x = s - y;
    // a x y
    // 0
    // 1 1 1

    // s - a
    string S = bitset<63>(a).to_string();
    reverse(S.begin(),S.end());

    int x = s - 2*a;
    for(int i=62;i>=0;i--)
    {
        if(S[i] == '0'&&x - ((ll)1<<(i)) >= 0)
        {
            x -= ((ll)1<<i);
        }
    }
    if(x == 0)
        cout<<"Yes\n";
    else
        cout<<"No\n";

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