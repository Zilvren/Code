#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    // 010
    // 110
    int n;cin>>n;
    string s;cin>>s;
    s = '#' + s;
    int cnt = 0;
    int f = 0;
    int ls1 = -lnf,fs1 = lnf;

    for(int i=n;i>=1;i--)
    {
        if(s[i] == '1')
        {
            ls1 = i;
            break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i] == '1')
        {
            fs1 = i;
            break;
        }
    }
    int sub = 0;
    for(int i=1;i<=n;i++)
    {
        if(s[i] == '0')
        {
            if(ls1>i&&fs1 <i)
            {
                sub = 2;
                break;
            }
            if(fs1 <i)
            {
                sub = 1;
            }
        }
    }
    for(int i = 1;i<=n;i++)
    {
        if(((s[i]- '0')^f)==1)
        {
            cnt+=2;
            f^=1;
        }
        else
            cnt++;
    }
    cout<<cnt - sub<<"\n";
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