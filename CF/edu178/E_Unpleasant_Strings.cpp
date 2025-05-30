#include<bits/stdc++.h>

#define lnf 0x3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,k;cin>>n>>k;
    string s;cin>>s;
    s = '#' + s;
    vector<vector<int>> ne(n+2,vector<int> (k,n+1));
    vector<int> g[27];
    for(int i=1;i<=n;i++)
    {
        g[s[i] - 'a'].push_back(i);
    }
    for(int i=0;i<26;i++)
        g[i].push_back(lnf);
    vector<int> dp(n+2);
    for(int i=n;i>=1;i--)
    {
        ne[i] = ne[i+1];
        dp[i] = 1 + dp[*max_element(ne[i].begin(),ne[i].end())];
        ne[i][s[i] - 'a'] = i;
    }
    int q;cin>>q;
    while(q--)
    {
        bool f = false;
        string t;cin>>t;
        int ls = 0;
        for(auto &c:t)
        {
            int p = upper_bound(g[c-'a'].begin(),g[c-'a'].end(),ls) - g[c-'a'].begin();
            if(p>=g[c-'a'].size())
            {
                f =true;
                break;
            }
            ls = g[c-'a'][p];
        }
        if(ls == lnf||f)
        {
            cout<<0<<"\n";
            continue;
        }
        cout<<dp[ls]<<"\n";
    }
}
/*
7 3
abacaba
1
b
5 1
aaaaa
1
aaaaaa

5 1
aaabb
1
a
*/
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

//    int t=1;
//    cin>>t;
//    while(t--)
    work();
}