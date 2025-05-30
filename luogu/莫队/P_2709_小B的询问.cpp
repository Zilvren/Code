#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    vector<array<int,3>> q(m+1);
    for(int i=1;i<=m;i++)
    {
        cin>>q[i][0]>>q[i][1];
        q[i][2] = i;
    }
    int len = sqrt(n);
    vector<int> block(n+1);
    for(int i=1;i<=n;i++)
        block[i] = i/len;
    sort(++q.begin(),q.end(),[&](array<int,3> a,array<int,3> b)
    {
        if(block[a[0]] != block[b[0]])
            return block[a[0]]<block[b[0]];
        if(block[a[0]]&1)
            return a[1]<b[1];
        return a[1]>b[1];
    });
    int l=1,r=0;
    int res =0 ;
    vector<int> cnt(k+1);
    auto add = [&](int p)
    {
        res -= cnt[a[p]]*cnt[a[p]];
        cnt[a[p]]++;
        res += cnt[a[p]]*cnt[a[p]];
    };
    auto sub = [&](int p)
    {
        res -= cnt[a[p]]*cnt[a[p]];
        cnt[a[p]]--;
        res += cnt[a[p]]*cnt[a[p]];
    };
    vector<int> ans(m+1);
    for(int i=1;i<=m;i++)
    {
        auto [ql,qr,p] = q[i];
        while(ql<l) add(--l);
        while(qr>r) add(++r);
        while(ql>l) sub(l++);
        while(qr<r) sub(r--);
        ans[p] = res;
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<"\n";
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