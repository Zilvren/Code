#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,k;cin>>n>>k;

    vector<int> a(n+1);

    vector<int> b(n+1);

    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=1;i<=n;i++)
        cin>>b[i];

    int s = -1;
    for(int i=1;i<=n;i++)
    {
        if(b[i] != -1)
        {
            if(s == -1)
            {
                s = a[i] + b[i];
            }
            else
            {
                if(a[i] + b[i] != s)
                {
                    cout<<0<<"\n";
                    return;
                }
            }
        }
    }
    if(s == -1)
    {
        int Max = *max_element(++a.begin(),a.end());
        int Min = *min_element(++a.begin(),a.end());
        cout<<Min + k - Max +1<<"\n";
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(b[i] == -1)
            {
                if(s - a[i] >=0&&s - a[i]<=k)
                    continue;
                else
                {
                    cout<<0<<"\n";
                    return ;
                }
            }
        }
        cout<<1<<"\n";
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