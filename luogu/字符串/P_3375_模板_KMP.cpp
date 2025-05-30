#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    string s,t;cin>>s>>t;
    int m = t.size();
    int n = s.size();
    t = '#' + t;
    s = '#' + s;
    vector<int> ne(m+1);
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
            ans.push_back(i-m+1),j = ne[j];
    }
    for(auto &t:ans)
        cout<<t<<"\n";

    for(int i=1;i<=m;i++)
        cout<<ne[i]<<" \n"[i==m];
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