#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
struct Trie
{
    struct Node
    {
        vector<int> son;
        int cnt;
        Node():cnt(0),son(70){}
    };
    map<int,int> mp;
    vector<Node> tr;
    Trie()
    {
        int idx = 0;
        for(int i='a';i<='z';i++)
            mp[i] = idx++;
        for(int i='A';i<='Z';i++)
            mp[i] = idx++;
        for(int i='0';i<='9';i++)
            mp[i] = idx++;
        tr.assign(1,Node());
    }
    int newNode()
    {
        tr.emplace_back();
        return tr.size()-1;
    }
    int insert(string s)
    {
        int u = 0;
        for(auto &c:s)
        {
            int v = mp[c];
            if(!tr[u].son[v])
                tr[u].son[v] = newNode();
            u = tr[u].son[v];
            tr[u].cnt++;
        }
        return u;
    }
    int query(string s)
    {
        int u = 0;
        for(auto &c:s)
        {
            int v = mp[c];
            if(!tr[u].son[v])
                return 0;
            u = tr[u].son[v];
        }
        return tr[u].cnt;
    }
};
void work()
{
    int n,q;cin>>n>>q;
    Trie tr;
    for(int i=1;i<=n;i++)
    {
        string s;cin>>s;
        tr.insert(s);
    }
    while(q--)
    {
        string s;cin>>s;
        cout<<tr.query(s)<<"\n";
    }

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