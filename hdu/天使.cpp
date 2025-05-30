#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
const int p = 1e9+7;
int qp(int a,int b)
{
    int ans = 1;
    while(b)
    {
        if(b&1)
            ans = ans*a,ans %=p;
        a = a*a,a%=p;
        b>>=1;
    }
    return ans;
}

void work()
{
    int n;cin>>n;

    vector<int> a(n+1);

    int sum = 0;
    for(int i=1;i<=n;i++)
        cin>>a[i],sum+=a[i],sum%=p;

    int ans1 = 0,ans2 = 1;
    int pre = 0;
    for(int i=1;i<=n;i++)
    {
        ans1 += a[i]%p*pre%p;
        ans1%=p;
        pre += a[i];
        pre%=p;
    }

    for(int i=n;i>=2;i--)
    {
        ans2 *=i%p*(i-1)%p*qp(2,p-2)%p;
        ans2%=p;
    }
    cout<<ans1<<" "<<ans2<<"\n";
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