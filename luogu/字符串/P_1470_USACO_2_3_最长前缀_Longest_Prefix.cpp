#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    vector<string> T;
    string t;
    while(cin>>t)
    {
        if(t == ".")
            break;
        T.push_back('#'+t);
    }
    string s;
    while(cin>>t)
        s+=t;
    int n = s.size();
    s = '#' + s;
    vector<vector<bool>> vis(T.size(),vector<bool>(n+1));
    auto kmp = [&](string t,int cnt)
    {
        int m = t.size()-1;
        vector<int> ne(m+1);
        ne[1] = 0;
        for(int i=2,j=0;i<=m;i++)
        {
            while(j&&t[j+1] != t[i]) j = ne[j];
            if(t[j+1] == t[i])j++;
            ne[i] = j;
        }
        vector<int> ans;
        for(int i=1,j=0;i<=n;i++)
        {
            while(j&&s[i] != t[j+1]) j = ne[j];
            if(s[i] == t[j+1]) j++;
            if(j == m)
            {
                vis[cnt][i] = true;
                j = ne[j];
            }
        }
    };
    for(int i=0;i<T.size();i++)
    {
        kmp(T[i],i);
    }

    vector<bool> dp(n+1);
    dp[0] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j = 0;j<T.size();j++)
        {
            if(vis[j][i]&&i-(T[j].size()-1)>=0)
                dp[i] = dp[i]|dp[i-(T[j].size()-1)];
        }
    }

    for(int i=n;i>=0;i--)
    {
        if(dp[i])
        {
            cout<<i<<"\n";
            return ;
        }
    }

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