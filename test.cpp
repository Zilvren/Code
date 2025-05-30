#include<bits/stdc++.h>
#define int long long
#define lnf 0u3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
struct AhoCorasick
{
    static constexpr int ALPHABET = 26;

    struct Node
    {
        int len;
        int fail;
        int cnt;
        int in;
        array<int, ALPHABET> son;

        Node() : len{0}, fail{0},cnt{0},in{0},son{} {}//分别表示到该节点路径长度,失配指针词频统计,入度，孩子
    };

    vector<Node> tr;
    AhoCorasick()
    {
        init();
    }

    void init()
    {
        tr.assign(1, Node());
    }

    int newNode()
    {
        tr.emplace_back();
        return tr.size() - 1;
    }

    int insert(string &a)
    {
        int p = 0;
        for (auto c: a)
        {
            int u = c - 'a';
            if (tr[p].son[u] == 0)
            {
                tr[p].son[u] = newNode();
                tr[tr[p].son[u]].len = tr[p].len + 1;
            }
            p = tr[p].son[u];
        }
        return p;
    }

    void getFail()
    {
        queue<int> q;
        for(int i=0;i<ALPHABET;i++)
            if(tr[0].son[i]!=0)
                q.push(tr[0].son[i]);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int i = 0; i < ALPHABET; i++)
            {
                if (tr[u].son[i] == 0)
                    tr[u].son[i] = tr[tr[u].fail].son[i];
                else
                {
                    tr[tr[u].son[i]].fail = tr[tr[u].fail].son[i];
                    tr[tr[tr[u].son[i]].fail].in++;
                    q.push(tr[u].son[i]);
                }
            }
        }
    }
    int size()
    {
        return tr.size();
    }
    void topu()
    {
        queue<int> Q;

        for(int i=0;i<tr.size();i++)
            if(tr[i].in==0)
                Q.push(i);

        while(!Q.empty())
        {
            int u=Q.front();
            Q.pop();
            int v=tr[u].fail;
            tr[v].in--;
            tr[v].cnt+=tr[u].cnt;
            if(tr[v].in==0)
                Q.push(v);
        }
    }

    void query(string s)
    {
        int u=0;
        for(int i=0;i<s.size();i++)
            u=tr[u].son[s[i]-'a'],tr[u].cnt++;
    }

};
void work()
{
    int n;cin>>n;
    vector<string> s(n+1);
    vector<int> idx(n+1);
    for(int i=1;i<=n;i++)
        cin>>s[i];
    string t;cin>>t;

    AhoCorasick ac;
    for(int i=1;i<=n;i++)
        idx[i] = ac.insert(s[i]);
    ac.getFail();

    ac.query(t);
    ac.topu();
    for(int i=1;i<=n;i++)
    {
        cout<<ac.tr[idx[i]].cnt<<"\n";
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