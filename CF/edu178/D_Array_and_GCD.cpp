#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N= 10000010;
int primes[N],cnt;
int pre[N];
bool st[N];

void get_primes(int n)
{
    st[0]=st[1]=1;
    for(int i=2;i<=n;i++)
    {
     	if(!st[i])
        {
            primes[cnt++]=i;
            for(int j=i+i;j<=n;j+=i)st[j]=true;
        }  
    }
}
void work()
{
    cout<<cnt;
    int n;cin>>n;
    vector<int> a(n+1);
    int sum = 0;
    for(int i=1;i<=n;i++)
        cin>>a[i],sum += a[i];
    
    int p = lower_bound(pre+1,pre+1e7,sum) - pre;
    cout<<n-p<<"\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    get_primes(1e7);
    for(int i=1;i<=1e7;i++)
        pre[i] = pre[i-1] + primes[i-1];
    // int t=1;
    // cin>>t;
    // while(t--)
        work();
}