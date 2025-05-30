#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
struct Node
{
    int i,w;
};
void work()
{
    int n;cin>>n;
    vector<Node> a(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>a[i].w,a[i].i = i;
        if(a[i].w == -1)
            a[i].w = lnf;
    }


    vector<int> in(n+1);
    vector<int> g[n+1];
    int p = 1;
    while(a.size()!=2)
    {
        vector<Node> t;
        t.push_back({0,0});
        for(int i=1;i<a.size();i++)
        {
            if(a[i].w == p)
            {
                if(i-1>=1&&a[i-1].w > a[i].w)
                {
                    int u = a[i].i,v = a[i-1].i;
                    if(p%2==0)
                        swap(u,v);
                    g[u].push_back(v);
                    in[v]++;
                }
                else if(i+1<a.size()&&a[i+1].w>=a[i].w)
                {
                    int u = a[i].i,v = a[i+1].i;
                    if(p%2==0)
                        swap(u,v);
                    g[u].push_back(v);
                    in[v]++;
                }
            }
            else
            {
                t.push_back(a[i]);
            }
        }
        p++;
        a = t;
    }

    int now = n;
    vector<int> ans(n+1);
    auto topu = [&]()
    {
        queue<int> Q;
        for(int i=1;i<=n;i++)
        {
            if(in[i] == 0)
                Q.push(i);
        }

        while(Q.size())
        {
            int u = Q.front();
            Q.pop();

            ans[u] = n--;

            for(auto &v:g[u])
            {
                in[v] -- ;
                if(in[v] == 0)
                    Q.push(v);
            }
        }
    };
    topu();
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" \n"[i==n];
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