#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;


void work()
{
    int n;
    cin>>n;
    vector<int> d(n+1);
    map<int,vector<int>> de1;
    map<int,vector<int>> de2;
    set<array<int,2>> e;
    auto addEdge = [&](int u)
    {
        for(int i=1;i<=n;i++)
        {
            if(d[i] == 1)
            {
                int t = u,v = i;
                if(t>v)
                    swap(t,v);
                e.insert({t,v});
            }
        }
    };
    auto ask = [&](int u)
    {
        de2.clear();
        cout<<"?"<<" "<<u<<endl;
        for(int i=1;i<=n;i++)
            cin>>d[i],de2[d[i]].push_back(i);
        cout<<endl;
    };
    ask(1);
    de1 = de2;
    addEdge(1);
    int ev=0,od =0;
    for(int i=1;i<=n;i++)
    {
        if(de1[i].size() == 0)
            break;
        if(i%2==0)
            ev+=de1[i].size();
        else
            od+=de1[i].size();
    }

    if(ev<od)
    {
        for(int i=2;i<=n;i+=2)
        {
            for(auto &u:de1[i])
            {
                ask(u);
                addEdge(u);
            }
        }
    }
    else
    {
        for(int i=1;i<=n;i+=2)
        {
            for(auto &u:de1[i])
            {
                ask(u);
                addEdge(u);
            }
        }
    }
    cout<<"!"<<endl;
    for(auto &[u,v]:e)
        cout<<u<<" "<<v<<endl;
}

signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0),cout.tie(0);

//    int t=1;
//    cin>>t;
//    while(t--)
    work();
}