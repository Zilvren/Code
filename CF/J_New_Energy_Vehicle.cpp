#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
struct Node
{
    int d,w;
    bool operator<(Node t)const
    {
        return d>t.d;
    }
};
void work()
{
    int n,m;cin>>n>>m;

    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];

    vector<int> now = a;
    priority_queue<Node> Q;
    vector<array<int,2>> t(m+1);
    for(int i=1;i<=m;i++)
        cin>>t[i][0]>>t[i][1];

    vector<bool> vis(n+1);
    for(int i=1;i<=m;i++)
    {
        Q.push({t[i][0],a[t[i][1]]});
        vis[t[i][1]] = 1;
    }

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            Q.push({lnf,a[i]});
        }
    }
    int p = 0;
    for(int i=1;i<=m;i++)
    {

        while(Q.size())
        {
            auto [d,w] = Q.top();
            Q.pop();
            if(p + w<t[i][0])
            {
                p+=w;
            }
            else
            {
                int tt = t[i][0] - p;
                p += t[i][0];
                w -=tt;
                if(w!=0)
                    Q.push({d,w});
                break;
            }
        }
        if(p<t[i][0])
            break;
        Q.push({lnf,a[t[i][1]]});
    }
    cout<<p<<"\n";
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