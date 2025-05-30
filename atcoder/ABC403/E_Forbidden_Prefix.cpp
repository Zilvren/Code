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
        int cnt;
        vector<int> son;//array<int,26>要快一点
        Node() : cnt{0},son(26) {}
    };
    vector<Node> tr;
    Trie()
    {
        tr.assign(1, Node());
    }
    int newNode()
    {
        tr.emplace_back();
        return tr.size() - 1;
    }
    void insert(string s,string t)
    {
        int u = 0;
        for(int i=0;i<s.size();i++)
        {
            int v = s[i] - 'a';
            if(!tr[u].son[v])
                tr[u].son[v] = newNode();
            u = tr[u].son[v];
            if(t == "Y")
                tr[u].cnt++;
        }
        if(t == "X")
            tr[u].cnt++;
    }
    int query(string s,string t)
    {
        int u = 0;
        int ans =0 ;
        for(int i=0;i<s.size();i++)
        {
            int v = s[i] - 'a';
            if(!tr[u].son[v])
                return ans;
            u = tr[u].son[v];
            if(t == "X")
                ans += tr[u].cnt;
        }
        int res = tr[u].cnt;
        if(t == "Y")
        {
            int u = 0;
            for(int i=0;i<s.size();i++)
            {
                int v = s[i] - 'a';
                if(!tr[u].son[v])
                    return ans;
                u = tr[u].son[v];
                tr[u].cnt -= res;
            }
            return res;
        }
        return ans;
    }
};
void work()
{
    int q;cin>>q;
    Trie X,Y;
    int now = 0;
    int ny = 0;
    while(q--)
    {
        int op;cin>>op;
        if( op == 1)
        {
            string x;cin>>x;
            if(X.query(x,"X") > 0)
            {
                cout<<ny - now<<"\n";
                continue;
            }
            X.insert(x,"X");
            int res = Y.query(x,"Y");
            now += res;
            cout<<ny - now<<"\n";
        }
        else
        {
            ny ++;
            string y;cin>>y;

            int res = X.query(y,"X");
            if(res > 0)
                now++;
            else
                Y.insert(y,"Y");
            cout<<ny - now<<"\n";
        }
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