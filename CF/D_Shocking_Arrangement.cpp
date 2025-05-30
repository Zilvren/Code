#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n;cin>>n;

    stack<int> a,b;
    int cnt0 = 0;
    for(int i=1;i<=n;i++)
    {
        int t;cin>>t;
        if(t>0)
            a.push(t);
        else if(t<0)
            b.push(t);
        else
            cnt0++;
    }

    if(a.size() == 0||b.size() == 0)
    {
        cout<<"No\n";
        return ;
    }
    cout<<"Yes\n";
    int sum = 0;
    for(int i=1;i<=n;i++)
    {
        if((sum<0||b.empty())&&a.size())
        {
            sum += a.top();
            cout<<a.top()<<" ";
            a.pop();
        }
        else if((sum>=0||a.empty())&&b.size())
        {
            sum += b.top();
            cout<<b.top()<<" ";
            b.pop();
        }
    }
    for(int i=1;i<=cnt0;i++)
        cout<<0<<" ";
    cout<<"\n";

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