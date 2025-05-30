#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,k;cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    vector<int> vis(n+1);
    int now = 0;
    vector<array<int,2>> path;
    path.push_back({0,0});
    while(1)
    {
        if(vis[now%n]==2||k == 0)
            break;
        
        if(vis[now%n] == 1)
            path.push_back({now % n,a[now % n]});
        vis[now%n]++;
        now += a[now%n];
        k--;
    }
    if(k == 0)
    {
        cout<<now<<"\n";
        return ;
    }
    n = path.size()-1;
    vector<int> s(n+1);
    for(int i=1;i<=n;i++)
        s[i] = s[i-1] + path[i][1];


    int ans = s[n] * (k/n);
    if(k%n == 0)
    {
        cout<<ans+now<<"\n";
    }
    else
    {
        k = (k-1)%n+1;
        cout<<ans + s[k] + now<<"\n";
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