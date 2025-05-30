#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,q;cin>>n>>q;

    vector<int> a(n+1);
    vector<int> mp(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]] = i;
    }

    while(q--)
    {
        int l,r,x;cin>>l>>r>>x;
        if(mp[x] < l||mp[x] > r)
        {
            cout<<-1<<" ";
            continue;
        }
        int dl = 0,dh = 0;
        bool f = false;
        int p = mp[x];
        int low = x-1,high = n - x;
        while(l<=r)
        {
            int mid = (l+r)/2;

            if(a[mid] == x)
            {
                f = true;
                break;
            }
            else if(a[mid] < x)
            {
                if(p>mid)
                {
                    l = mid + 1;
                    low --;
                }
                else
                {
                    r = mid-1;
                    high--;
                    if(high < 0)
                        break;
                    dh++;
                }
            }
            else if(a[mid] > x)
            {
                if(p>mid)
                {
                    l = mid + 1;
                    low --;
                    if(low < 0)
                        break;
                    dl++;
                }
                else
                {
                    r = mid-1;
                    high --;
                }
            }
        }
        if(f)
            cout<<min(dl,dh)*2 + max(dl-min(dl,dh),dh-min(dl,dh))*2<<" ";
        else
            cout<<-1<<" ";
    }
    cout<<"\n";
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