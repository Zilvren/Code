#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n;cin>>n;
    string s;cin>>s;
    s = '#' + s;
    if(s[1] == s[n])
    {
        if(s[1] == 'A')
            cout<<"Alice\n";
        else
            cout<<"Bob\n";
    }
    else
    {
        if(s[1] == 'B')
        {
            if(s[n-1] == 'B')
                cout<<"Bob\n";
            else
                cout<<"Alice\n";
        }
        else
        {
            int cnt = count(++s.begin(),s.end(),'B');
            if(cnt>=2)
                cout<<"Bob\n";
            else
                cout<<"Alice\n";
        }
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