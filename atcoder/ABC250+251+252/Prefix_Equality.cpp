#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
mt19937_64 rd(1);
void work()
{
    int n;cin>>n;
    vector<int> a(n+1),b(n+1);
    map<int,int> hash1,hash2;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        hash1[a[i]] = rd();
        hash2[a[i]] = rd();
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        hash1[b[i]] = rd();
        hash2[b[i]] = rd();
    }

    vector<int> preha1(n+1),preha2(n+1),prehb1(n+1),prehb2(n+1);
    set<int> S;

    for(int i=1;i<=n;i++)
    {
        if(S.count(a[i]))
        {
            preha1[i] = preha1[i-1];
            preha2[i] = preha2[i-1];
        }
        else
        {
            preha1[i] = (preha1[i-1] ^ hash1[a[i]]);
            preha2[i] = (preha2[i-1] ^ hash2[a[i]]);
        }
        S.insert(a[i]);
    }
    S.clear();
    for(int i=1;i<=n;i++)
    {
        if(S.count(b[i]))
        {
            prehb1[i] = prehb1[i-1];
            prehb2[i] = prehb2[i-1];
        }
        else
        {
            prehb1[i] = (prehb1[i-1] ^ hash1[b[i]]);
            prehb2[i] = (prehb2[i-1] ^ hash2[b[i]]);
        }

        S.insert(b[i]);
    }
    int q;cin>>q;
    while(q--)
    {
        int x,y;cin>>x>>y;
        if(preha1[x] == prehb1[y]
        &&preha2[x] == prehb2[y])
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
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