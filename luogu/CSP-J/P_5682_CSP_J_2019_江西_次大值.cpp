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
    a.erase(unique(++a.begin(),a.end()),a.end());

    if(a.size()>3)
        cout<<max(a[a.size()-3],a[a.size()-1]%a[a.size()-2]);
    else if(a.size() == 3)
        cout<<a[2]%a[1];
    else
        cout<<-1;
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