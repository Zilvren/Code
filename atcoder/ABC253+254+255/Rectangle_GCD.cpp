#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,q;cin>>n>>q;
    vector<int> a(n+1),b(n+1),a_b(n+1),b_b(n+1);

    for(int i=1;i<=n;i++)
        cin>>a[i],a_b[i] = abs(a[i] - a[i-1]);

    for(int i=1;i<=n;i++)
        cin>>b[i],b_b[i] = abs(b[i] - b[i-1]);

    vector<int> lg(n+1);

    for(int i=2;i<=n;i++)
        lg[i] = lg[i/2] + 1;

    vector<vector<int>> gcdb(n+1,vector<int>(lg[n]+1)),gcda(n+1,vector<int>(lg[n]+1));
    for(int i=1;i<=n;i++)
        gcdb[i][0] = b_b[i],
                gcda[i][0] = a_b[i];
    for(int len = 1;len<=lg[n];len++)
        for(int l = 1;l+(1<<(len-1))<=n;l++)
            gcdb[l][len] = __gcd(gcdb[l][len-1],gcdb[l+(1<<(len-1))][len-1]),
            gcda[l][len] = __gcd(gcda[l][len-1],gcda[l+(1<<(len-1))][len-1]);

    auto get_gcdb = [&](int l,int r)
    {
        if(l>r)
            return (ll)0;
        int len = lg[r-l+1];
        return __gcd(gcdb[l][len],gcdb[r - (1<<len) +1][len]);
    };
    auto get_gcda = [&](int l,int r)
    {
        if(l>r)
            return (ll)0;
        int len = lg[r-l+1];
        return __gcd(gcda[l][len],gcda[r - (1<<len) +1][len]);
    };

    while(q--)
    {
        int h1,h2,w1,w2;
        cin>>h1>>h2>>w1>>w2;
        int aa= get_gcda(h1+1,h2);
        int ba=get_gcdb(w1+1,w2);
        cout<<__gcd(a[h1] + b[w1],__gcd(get_gcda(h1+1,h2),get_gcdb(w1+1,w2)))<<"\n";
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