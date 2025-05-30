#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,q;cin>>n>>q;

    vector<int> d(q+1);

    for(int i=1;i<=q;i++)
        cin>>d[i];

    for(int i=1;i<n;i++)
        cout<<i<<" "<<i+1<<"\n";

    int now = n-1;
    int v = n-1;
    for(int i=1;i<=q;i++)
    {
        if(now == d[i])
        {
            cout<<"-1 -1 -1\n";
        }
        else
        {
            cout<<n<<" "<<v<<" "<<d[i]<<"\n";
            now = d[i];
            v = d[i];
        }
    }
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