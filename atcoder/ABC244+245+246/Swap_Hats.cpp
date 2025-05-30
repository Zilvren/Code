#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
//G B A
//A G B
void work()
{
    string s(4,'0');
    cin>>s[1]>>s[2]>>s[3];
    
    string t(4,'0');
    cin>>t[1]>>t[2]>>t[3];
    int cnt =0 ;
    for(int i=1;i<=3;i++)
    {
        if(s[i] != t[i])
            cnt++;
    }
    if(cnt == 2)
        cout<<"No\n";
    else if(cnt == 3)
        cout<<"Yes\n";
    else if(cnt == 0)
        cout<<"Yes\n";
    
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