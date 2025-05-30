#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,k,x;cin>>n>>k>>x;

    vector<int> a(n+1);

    int sum = 0;
    for(int i=1;i<=n;i++)
        cin>>a[i],sum+=a[i];

    vector<int> suf(n+2);

    for(int i=n;i>=1;i--)
        suf[i] = suf[i+1] + a[i];
    
    if(sum*k < x)
    {
        cout<<"0\n";
        return ;
    }
    int cnt =  x/sum;
    x%=sum;
    if(x == 0)
    {
        cout<<(k-cnt)*n+1<<"\n";
        return ;
    }
    int p = -1;
    for(int i=n;i>=1;i--)
    {
        if(suf[i] >= x)
        {
            p = i;
            break;
        }
    }
    cout<<(k-cnt-1)*n + p <<"\n";
    
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