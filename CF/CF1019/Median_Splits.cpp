#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,k;cin>>n>>k;
    vector<int> a(n+1),s(n+1);
    vector<bool> vis(n+1);

    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=1;i<=n;i++)
    {
        s[i] += s[i-1] + (a[i] <= k);
        if(s[i]*2 >= i)
            vis[i] = 1;
    }
    auto check1 = [n,k](vector<int> a) -> bool
    {
        vector<int> s(n+1);
        vector<bool> vis(n+1);
        for(int i=1;i<=n;i++)
            s[i] += s[i-1] + ((a[i] <= k)?1:0);
        
        vector<int> suf(n+2);
        suf[n+1] = -lnf;
        for(int i=n;i>=1;i--)
            suf[i] = max(suf[i+1],2*s[i] - i);

        for(int i=1;i<n-1;i++)
        {
            if(2*s[i] >= i&&suf[i+1] >= 2*s[i]-i)
            {
                //(s[r] - s[i])*2 >= r-i
                //2*s[r] - 2*s[i] >= r - i
                //2*s[r] - r >= 2*s[i] - i
                return true;
            }
        }
        return false;
    };
    auto t = a;
    reverse(++t.begin(),t.end());
    if(check1(a)||check1(t))
    {
        cout<<"YES\n";
        return ;
    }
    int l = n+1;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])
        {
            l = i;
            break;
        }
    }
    for(int i=l+1;i<n;i++)
    {
        if((s[n] - s[i])*2>=(n-i)&&l<i)
        {
            cout<<"YES\n";
            return ;
        }
    }
    cout<<"NO\n";
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