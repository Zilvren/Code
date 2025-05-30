#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,m;cin>>n>>m;

    string s;cin>>s;
    s = '#' + s;
    
    //右边的第一个1，左边的第一个0
    vector<int> lz(n+1),ro(n+2);
    ro[n+1] = n+1;
    for(int i=1;i<=n;i++)
    {
        if(s[i] == '0')
            lz[i] = i ;
        else
            lz[i] = lz[i-1]; 
    }

    for(int i=n;i>=1;i--)
    {
        if(s[i] == '1')
            ro[i]  = i;
        else
            ro[i] = ro[i+1];
    }

    set<array<int,2>> S;
    for(int i=1;i<=m;i++)
    {
        int l,r;cin>>l>>r;
        if(ro[l]<lz[r])
        {
            S.insert({ro[l],lz[r]});
        }
        else
            S.insert({0,0});
    }
    cout<<S.size()<<"\n";
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