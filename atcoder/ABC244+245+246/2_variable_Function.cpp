#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int x;cin>>x;
    int ans = lnf;
    for(int i=0;i<=1e6;i++)
    {
        int l = 0,r = 1e6;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if((i*i*i +i*i*mid + mid*mid*i + mid*mid*mid)>=x)
            {
                ans = min(ans,(i*i*i +i*i*mid + mid*mid*i + mid*mid*mid));
                r = mid-1;
            }
            else
                l = mid+1;
        }
    }
    cout<<ans;


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