#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
bool is_primes(int x)
{
    if(x<2)
        return false;

    for(int i=2;i<=x/i;i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}
void work()
{
    int a,b,c,d;cin>>a>>b>>c>>d;

    bool f = false;
    for(int i=a;i<=b;i++)
    {
        bool f =true;
        for(int j=c;j<=d;j++)
        {
            if(is_primes(i+j))
            {
                f = false;
                break; 
            }
        }
        if(f)
        {
            cout<<"Takahashi\n";
            return ;
        }
    }
    cout<<"Aoki\n";
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