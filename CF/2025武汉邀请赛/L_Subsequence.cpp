#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];

    sort(++a.begin(),a.end());

    int ans = 1;
    for(int l=1;l<=n;l++)
        for(int r = l;r<=n;r++)
        {
            int L = l,R =r;
            if((a[l]+a[r])%2!=0)continue;
            int x = (a[L]+a[R])/2;
            int resr = 0;
            while(L<=R)
            {
                int mid = (L+R)/2;
                if(a[mid] <=x)
                    L = mid+1,resr = mid;
                else
                    R = mid-1;
            }
            if(a[resr] != x)
                continue;
            
            int resl = 0;
            L = l,R = r;
            while(L<=R)
            {
                int mid = (L+R)/2;
                if(a[mid] < x)
                    L = mid+1;
                else
                    R = mid-1,resl = mid;
            }

            int len = r - l + 1;
            int m = (l+r)/2;
            //l+(r - l)/2 
            if(resl <= m && m <= resr)
            {
                ans = max(len,ans);
            }
            else if(resr<m)
            {
                ans=max(ans,2*(resr-l+1));
            }
            else
            {
                ans=max(ans,2*(r-resl+1)-1);
            }
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