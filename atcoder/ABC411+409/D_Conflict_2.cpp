#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
struct Trie
{
    vector<vector<int>> ch;
    vector<int> fa;
    vector<int> c;
    int idx = 0;
    map<char,int> mp;
    Trie(int n):ch(n+1,vector<int>(32)),fa(n+1),c(n+1)
    {
        int id = 0;
        for(char i = 'a' ;i<='z';i++)mp[i] = id++;
    }

    int insert(string s,int p)
    {
        int ans = 0;
        int u = p;
        for(int i=0;i<s.size();i++)
        {
            int v = mp[s[i]];
            if(!ch[u][v])
            {
                ch[u][v] =++idx;
                c[idx] = mp[s[i]];
            }
            fa[ch[u][v]] = u;
            u = ch[u][v];
        }
        return u;
    }

};
void work()
{
    int n,q;cin>>n>>q;
    Trie tr(2e5);
    vector<int> idx(n+1);
    int ans = 0;
    while(q--)
    {
        int op;cin>>op;
        if(op == 2)
        {
            int i;string s;
            cin>>i>>s;
            idx[i] = tr.insert(s,idx[i]);
        }
        else if(op == 1)
        {
            int i;cin>>i;
            idx[i] = ans;
        }
        else
        {
            int i;cin>>i;
            ans = idx[i];
        }
    }
    string s = "";
    function<void(int)> dfs = [&](int u)
    {
        if(u == 0)
            return ;
        s += tr.c[u]+'a';
        dfs(tr.fa[u]);
    };
    dfs(ans);
    reverse(s.begin(),s.end());
    cout<<s;
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