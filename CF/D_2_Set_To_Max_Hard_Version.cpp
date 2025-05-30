#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n;cin>>n;
    vector<int> a(n+1),b(n+1);

    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    for(int i=1;i<=n;i++)
        cin>>b[i];
    
    vector<int> lg(n+1);
    lg[0] = -1;
    for(int i=1;i<=n;i++)
        lg[i] = lg[i/2]+1;
    vector<vector<int>> fa(n+1,vector<int>(lg[n]+2)),fb(n+1,vector<int>(lg[n]+2,lnf));
    for(int i=1;i<=n;i++)
        fa[i][0] = a[i],fb[i][0] = b[i];;
    
    for(int len = 1;len <= lg[n];len++)
        for(int i=1;i+(1<<(len-1))<=n;i++)
            fa[i][len] = max(fa[i][len-1] ,fa[i+(1<<(len-1))][len-1]),fb[i][len] = min(fb[i][len-1] ,fb[i+(1<<(len-1))][len-1]);
    
    map<int,int> mp;

    vector<array<int,2>> v(n+1);
    //v[i][0]表示左边，v[i][1]表示右边
    for(int i=1;i<=n;i++)
    {
        mp[a[i]] = i;
        if(mp.count(b[i]))
            v[i][0] = mp[b[i]];
        else
            v[i][0] = -1;
    }
    mp.clear();

    for(int i=n;i>=1;i--)
    {
        mp[a[i]] = i;
        if(mp.count(b[i]))
            v[i][1] = mp[b[i]];
        else
            v[i][1] = -1;
    }
    auto Max = [&](int l,int r)
    {
        int len = lg[r-l+1];
        return max(fa[l][len],fa[r-(1<<len)+1][len]);
    };
    auto Min = [&](int l,int r)
    {
        int len = lg[r-l+1];
        return min(fb[l][len],fb[r-(1<<len)+1][len]);
    };
    for(int i=1;i<=n;i++)
    {
        int l = v[i][0],r = v[i][1];
        bool fl =0,fr = 0;
        if(l!=-1&&Max(l,i) == b[i]&&Min(l,i)>=b[i])
            fl = true;
        if(r!=-1&&Max(i,r) == b[i]&&Min(i,r)>=b[i])
            fr = true;
        // while(l>=1&&a[l]<b[i]&&b[l]>=b[i])l--;

        // while(r<=n&&a[r]<b[i]&&b[r]>=b[i])r++;

        if(!fl&&!fr)
        {
            cout<<"NO\n";
            return ;
        }
    }
    cout<<"YES\n";
    
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