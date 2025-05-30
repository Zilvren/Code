#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;

struct Node
{
    int u,v,ne;
};
void work()
{
    int n,m;
    cin>>n>>m;
    vector<int> h(2*n+1,-1);
    vector<int> low(2*n+1),dfn(2*n+1),col(2*n+1),S;
    vector<Node> e(2*m+1);
    int ti=1;
    int idx = 0;
    int cnt=0;
    auto add=[&](int u,int v)
    {
        e[idx] = {u,v,h[u]};
        h[u] = idx++;
    };
    function<void(int)> tarjan = [&](int u)
    {
        low[u] = dfn[u] = ti++;
        S.push_back(u);
        for(int i=h[u];i!=-1;i = e[i].ne)
        {
            int v = e[i].v;
            if(!dfn[v])
            {
                tarjan(v);
                low[u] = min(low[u],low[v]);
            }
            else if(col[v] == 0)
                low[u] = min(low[u],dfn[v]);
            //low[u] = min(low[u],low[v]);在这里两个都一样
        }
        if(low[u] == dfn[u])
        {
            cnt++;
            int pre;
            do
            {
                pre = S.back();
                col[pre] = cnt;
                S.pop_back();
            }while(pre!=u);
        }
    };

    for(int i=1;i<=m;i++)
    {
        int a,b;cin>>a>>b;
        int f1= 1,f2 = 1;
        add(a+!f1*n,b+f2*n);
        add(b+!f2*n,a+f1*n);
    }

    for(int i=1;i<=2*n;i++)
        if(!dfn[i])
            tarjan(i);

    int ans =0;

    for(int i=1;i<=n;i++)
    {
        if(col[i] == col[i+n])
        {
            cout<<"No\n";
            return ;
        }
    }
    cout<<"Yes\n";
    vector<int> a,b;
    for(int i=1;i<=n;i++)
    {
        if(col[i]>=col[i+n])
            b.push_back(i);
        else
            a.push_back(i);
    }
    for(auto &t:a)
        cout<<t<<" ";
    cout<<"\n";
    for(auto &t:b)
        cout<<t<<" ";

    cout<<"\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   int t=1;
   cin>>t;
   while(t--)
    work();

    return 0;
}