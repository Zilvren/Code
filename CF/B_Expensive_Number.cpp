#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    string s;cin>>s;

    int p = s.size()-1;
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i] != '0')
        {
            p = i;
            break;
        }
    }
    int cnt = 0;
    for(int i=0;i<p;i++)
    {
        if(s[i]!='0')
            cnt++;
    }
    cout<<cnt + s.size() - p + 1<<"\n";
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