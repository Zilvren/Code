#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    string s;
    while(cin>>s)
    {
        if(s == ".")
            break;
        int n = s.size();
        s = '#' + s;

        vector<int> ne(n+1);
        ne[1] = 0;
        for(int i=2,j =0;i<=n;i++)
        {
            while(j&&s[i] != s[j+1])
                j = ne[j];

            if(s[i] == s[j+1])
                j++;
            ne[i] = j;
        }
        if(n%(n-ne[n])==0)
            cout<<n/(n-ne[n])<<"\n";
        else
            cout<<1<<"\n";
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