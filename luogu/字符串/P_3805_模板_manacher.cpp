#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
int manacher(string s)
{
    string t = "^#";

    for(auto c:s)
        t+=c,t+='#';
    t+='$';
    s = t;
    vector<int> p(s.size());
    int c = 0,r = 0;
    for(int i=1;i<s.size()-1;i++)
    {
        if(i <= r) p[i] = min(r - i,p[2*c - i]);
        while(s[i-p[i]-1] == s[i+p[i]+1])p[i]++;
        if(i+p[i]>r)
        {
            r = i+p[i];
            c = i;
        }
    }
    return *max_element(p.begin(),p.end());
}
void work()
{
    string s;cin>>s;
    cout<<manacher(s);
    
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