#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,k;cin>>n>>k;
    string s;cin>>s;
    s = '.'+s+'.';

    int cnto = 0;
    for(int i=1;i<=n;i++)
    {
        if(s[i] == 'o')
            s[i-1] = '.',s[i+1] = '.',cnto ++;
    }
    if(cnto == k)
    {
        for(int i=1;i<=n;i++)
        {
            if(s[i] == '?')
                cout<<".";
            else
                cout<<s[i];
        }
        return ;
    }
    int res = 0;
    int cntc=0;
    bool fev = 0;
    for(int i=1;i<=n+1;i++)
    {
        if(s[i] == '?')
            cntc++;
        else
        {
            res += (cntc+1)/2;
            cntc = 0;
        }
    }

    if(res + cnto == k)
    {
        for(int i=1;i<=n+1;i++)
        {
            if(s[i] == '?')
                cntc++;            
            else
            {
                if(cntc %2 == 0)
                {
                    cntc = 0;
                    continue;
                }
                int st =i-cntc;
                for(int j=st;j<i;j++)
                {
                    if(j%2==st%2)
                        s[j] = 'o';
                    else
                        s[j] = '.';
                }
                cntc = 0;
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<s[i];

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