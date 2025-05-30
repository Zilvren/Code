#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    map<int,pair<int,int>>mp;
    bool f=1;
    while(m--)
    {
        int p,l,r;
        cin>>p>>l>>r;
        int L=mp[p].first,R=mp[p].second;
        if(l>R||r<L)
        {
            f=0;
            continue;
        }
        if(L==0&&R==0)
        {
            mp[p]={l,r};
        }
        else
        {
            mp[p].first=max(L,l);
            mp[p].second=min(R,r);
        }
    }
    if(!f)
    {
        cout<<"-1\n";
        return;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int l=mp[i].first;
        int r=mp[i].second;
        if(l==0&&r==0)
        {
            continue;
        }
        ans+=min(abs(a[i]-r),abs(a[i]-l));
    }
    cout<<ans<<"\n";
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