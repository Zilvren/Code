#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,x;cin>>n>>x;
    string s;cin>>s;
    s = '#' + s;
    deque<char> Q;
    for(int i=1;i<=n;i++)
    {
        if(s[i] == 'U')
        {
            if(Q.size()&&Q.back() != 'U')
                Q.pop_back();
            else
                Q.push_back(s[i]);
        }
        else 
            Q.push_back(s[i]);
    }
    while(Q.size())
    {
        char c = Q.front();
        Q.pop_front();
        if(c == 'L')
            x = x*2;
        else if(c == 'R')
            x = x*2+1;
        else
            x = x/2;
    }
    cout<<x;
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