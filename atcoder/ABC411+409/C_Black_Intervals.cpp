#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,q;cin>>n>>q;
    vector<bool> vis(n+2);
    int ans = 0;
    while(q--)
    {
        int a;cin>>a;

        if(vis[a])
        {
            if(vis[a-1]|vis[a+1])
            {
                if(vis[a-1]&&vis[a+1])
                    ans++;
            }
            else
            {
                ans--;
            }
            vis[a] = !vis[a];
        }
        else
        {
            if(vis[a-1]|vis[a+1])
            {
                if(vis[a-1]&&vis[a+1])
                    ans--;
            }
            else
            {
                ans++;
            }
            vis[a] = !vis[a];
        }
        cout<<ans<<"\n";
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