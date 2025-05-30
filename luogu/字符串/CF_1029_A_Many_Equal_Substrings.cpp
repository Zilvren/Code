#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,k;cin>>n>>k;
    string s;cin>>s;
    s = '#' + s;

    vector<int> ne(n+1);

    for(int i=2,j=0;i<=n;i++)
    {
        while(j&&s[i]!=s[j+1]) j = ne[j];
        if(s[j+1] == s[i])
            j++;
        ne[i] = j;
    }
    string t = s.substr(ne[n]+1);
    for(int i=1;i<k;i++)
        s+=t;
    cout<<s.substr(1);
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