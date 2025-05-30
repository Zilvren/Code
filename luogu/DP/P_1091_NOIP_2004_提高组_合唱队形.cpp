#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp1[105];
int dp2[105];
void work()
{
    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i])
            {
                dp1[i]=max(dp1[i],dp1[j]+1);
            }
        }
    }
    for(int i=n;i>0;i--)
    {
        for(int j=n+1;j>i;j--)
        {
            if(a[j]<a[i])
            {
                dp2[i]=max(dp2[i],dp2[j]+1);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp1[i]+dp2[i]);
    }
    cout<<n-ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--)
    {
        work();
    }
    return 0;
}