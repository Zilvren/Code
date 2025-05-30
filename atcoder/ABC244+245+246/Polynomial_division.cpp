#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,m;cin>>n>>m;
    n++;
    m++;
    vector<int> a(n+1);
    vector<int> c(n+m+2);
    vector<int> b(m+1);

    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m+n-1;i++)
        cin>>c[i];


    //2 4 6
    //  1 2
    for(int i=m+n-1;i>=n;i--)
    {
        int ans =0 ;
        for(int j=1;j<=n;j++)
        {
            if(1<=i+1-j&&i+1-j<=m)
                ans += a[j]*b[i+1-j];
        }
        //ans +a[n]*b[i] == c[i + n - 1]
        b[(i-n)+1] = (c[i] - ans)/a[i+1 -((i-n)+1)];
    }
    for(int i=1;i<=m;i++)
        cout<<b[i]<<" \n"[i==m];
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