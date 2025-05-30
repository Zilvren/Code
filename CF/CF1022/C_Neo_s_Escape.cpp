#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
struct Node
{
    int w,i;
    bool operator <(Node t) const
    {
        return w<t.w;
    }
};
void work()
{
    int n;cin>>n;
    vector<int> a;
    a.push_back(0);
    priority_queue<Node> Q;//还没被按下的
    for(int i=1;i<=n;i++)
    {
        int t;cin>>t;
        if(a.back() != t)
            a.push_back(t);
    }
    for(int i=1;i<a.size();i++)
    {
        Q.push({a[i],i});
    }
    vector<int> vis(n+2);//表示可以被按下不需要添加的位置
    int ans =0 ;
    while(Q.size())
    {
        auto [w,i] = Q.top();
        Q.pop();
        if(vis[i])
        {
            vis[i+1] = 1;
            vis[i-1] = 1;
            continue;
        }

        vis[i] = 1;
        ans ++;
        vis[i-1] = 1,vis[i+1] = 1;
    }
    cout<<ans<<"\n";

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