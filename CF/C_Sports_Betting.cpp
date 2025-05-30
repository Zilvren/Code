#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n;cin>>n;
    vector<int> a(n);
    map<int,int> mp;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }

    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());

    for(int i=0;i<a.size();)
    {
        if(mp[a[i]]>=4)
        {
            cout<<"YES\n";
            return ;
        }
        int j = i+1;
        if(mp[a[i]]>=2)
        {

            while(j<a.size()&&a[j]-1 == a[j-1])
            {
                if(mp[a[j]]>=2)
                {
                    cout<<"YES\n";
                    return ;
                }
                j++;
            }
        }
        i = j;
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