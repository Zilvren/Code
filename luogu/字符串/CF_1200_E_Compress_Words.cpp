#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 1e5+7;
ull base = 131;
ull mod1 = 19260817, mod2 = 1e9 + 7;
void work()
{
    vector<ull> p1(1e6+7);
    p1[0] = 1;
    for(int i=1;i<=1e6;i++)
        p1[i] = p1[i-1]*base%mod1;
    vector<ull> p2(1e6+7);
    p2[0] = 1;
    for(int i=1;i<=1e6;i++)
        p2[i] = p2[i-1]*base%mod2;
    int n;cin>>n;
    vector<string> a(n+1);
    auto get_hash1 = [&](string s)
    {
        int n = s.size();
        s = '#' + s;
        vector<ull> h(n+1);

        for(int j=1;j<=n;j++)
            h[j] = (h[j-1] *base%mod1 + s[j])%mod1;
        return h;
    };
    auto get_hash2 = [&](string s)
    {
        int n = s.size();
        s = '#' + s;
        vector<ull> h(n+1);

        for(int j=1;j<=n;j++)
            h[j] = (h[j-1] *base%mod2 + s[j])%mod2;
        return h;
    };
    auto query1 = [&](vector<ull> &h,int l,int r)
    {
        l++,r++;
        return (h[r] - h[l-1]*p1[r - l + 1]%mod1+mod1)%mod1;
    };
    auto query2 = [&](vector<ull> &h,int l,int r)
    {
        l++,r++;
        return (h[r] - h[l-1]*p2[r - l + 1]%mod2+mod2)%mod2;
    };
    string s = "";
    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    s = a[1];
    auto hs1 = get_hash1(s);
    auto hs2 = get_hash2(s);
    for(int i=2;i<=n;i++)
    {
        int n = s.size()-1,m=a[i].size()-1;
        auto ha1 = get_hash1(a[i]);
        auto ha2 = get_hash2(a[i]);
        bool f = false;
        for(int j=min(m,n);j>=0;j--)
        {
            if(query1(ha1,0,j) == query1(hs1,n-j,n)
            &&query2(ha2,0,j) == query2(hs2,n-j,n))
            {
                for(int k=j+1;k<=m;k++)
                    s += a[i][k],hs1.push_back((hs1.back() *base%mod1 + a[i][k])%mod1)
                    ,hs2.push_back((hs2.back() *base%mod2 + a[i][k])%mod2);
                f = true;
                break;
            }
        }
        if(!f)
        {
            for(int k=0;k<=m;k++)
                s += a[i][k],hs1.push_back((hs1.back() *base%mod1 + a[i][k])%mod1)
                ,hs2.push_back((hs2.back() *base%mod2 + a[i][k])%mod2);
        }
    }
    cout<<s;
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