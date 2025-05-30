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

    vector<int> ev,od;
    for(int i=2;i<=n;i+=2)
        ev.push_back(a[i]);

    for(int i=1;i<=n;i+=2)
        od.push_back(a[i]);

    sort(ev.begin(),ev.end());
    sort(od.begin(),od.end());
    int pod = 0;
    int pev = 0;
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)
            cout<<od[pod++]<<" ";
        else
            cout<<ev[pev++]<<" ";
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