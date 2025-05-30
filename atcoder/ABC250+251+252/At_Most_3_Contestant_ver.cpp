#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n;cin>>n;
    vector<int> a;
    a.push_back(1e6);
    for(int i=1;i<=99;i++)
        a.push_back(i),a.push_back(i*100),a.push_back(i*10000);

    cout<<a.size()<<"\n";
    for(auto &t:a)
        cout<<t<<" ";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    //  int t=1;
    //  cin>>t;
    //  while(t--)
        work();
}