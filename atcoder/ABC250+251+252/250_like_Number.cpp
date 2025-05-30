#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N=1000007;
int primes[N],cnt;
bool st[N];

void get_primes(int n)
{
    st[0]=st[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!st[i])primes[cnt++]=i;
        for(int j=0;primes[j]<=n/i;j++)
        {
            //n只会被最小的质因子筛掉
            //1.i%pj==0
            //	pj一定是i的最小质因子，pj也一定是pj*i的最小质因子
            //2.i%pj!=0
            //  pj一定小于i的所有质因子，pj也一定是pj*i的最小质因子
            //对于一个合数x，必有一个最小质因子假设为pj,当i>pj时，质数表里一定有pj，易证pj<=x/pj->pj*pj<=x,当i枚举到x/pj时，质数表里一定有pj，那么x就会被pj*i筛掉

            st[primes[j]*i]=true;
            if(i%primes[j]==0)break;//primes[j]一定是i的最小质因子.
        }
    }
}//线性筛,任何一个数都是被最小质因子筛掉.
void work()
{
    int n;cin>>n;
    int p = 0;
    int ans = 0;
    for(int i=cnt-1;i>=0&&p<i;)
    {
        if(primes[i]*primes[i]*primes[i] * primes[p]<=n)
        {
            ans += i - p;
            p++;
        }
        else
            i--;
    }
    cout<<ans<<"\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    get_primes(N-2);
    // int t=1;
    // cin>>t;
    // while(t--)
    work();
}