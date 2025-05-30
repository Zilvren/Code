#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    string s;cin>>s;
    int n = s.size();

    s = '#' + s;

    vector<int> ne(n+1);
    for(int i=2,j=0;i<=n;i++)
    {
        while(j&&s[i]!=s[j+1])
            j = ne[j];

        if(s[i] == s[j+1])
            j++;
        ne[i] = j;
    }
    int Maxl = 0;
    for(int i=2;i<n;i++)
        Maxl = max(ne[i],Maxl);
    int j = n;

    while(ne[j]>Maxl)
        j = ne[j];
    if(ne[j]!=0)
        cout<<s.substr(1,ne[j]);
    else
        cout<<"Just a legend";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

//    int t=1;
//    cin>>t;
//    while(t--)
    work();
}