#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
struct Node
{
    int l,r;
};

void work()
{
    int n;cin>>n;
    vector<int> a(n+1),b(n+1),mid(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i],mid[b[i]] = i;

    vector<Node> tr(n+1);
    //中左右
    //左中右
    bool t = true;
    function<int(int,int,int,int)> dfs =[&](int l1,int r1,int l2,int r2)
    {
        if(l1>r1||l2>r2)
            return (ll)0;
        if(!t)
            return (ll)0;
        int res = a[l1];
        int i = mid[res];
        if(i<l2||i>r2)
        {
            t = 0;
            return (ll)0;
        }
        tr[res].l = dfs(l1+1,l1+i-l2,l2,i-1);
        tr[res].r = dfs(r1 - (r2 - i)+1,r1,i+1,r2);

        return res;
    };
    int root = dfs(1,n,1,n);
    if(root == 1&&t)
    {
        for(int i=1;i<=n;i++)
            cout<<tr[i].l<<" "<<tr[i].r<<"\n";
    }
    else
    {
        cout<<-1<<"\n";
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