#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
struct SegmentTree
{
    vector<int> info,tag1,tag2;
    vector<int> a;
    SegmentTree(vector<int> a,int n):info(4*n),tag1(4*n),tag2(4*n),a(a){}

    void BuildTree(int idx,int l,int r)
    {
        if(l == r)
        {
            info[idx]=a[l];
            return ;
        }
        int mid = (l+r)/2;
        BuildTree(idx*2,l,mid);
        BuildTree(idx*2+1,mid+1,r);
        info[idx] = max(info[idx*2],info[idx*2+1]);
    }
    void pushadd(int idx)
    {
        info[idx*2] += tag1[idx];
        info[idx*2+1] += tag1[idx];

        tag1[idx*2] +=tag1[idx];
        tag1[idx*2+1] += tag1[idx];

        tag1[idx] = 0;
    }
    void pushfix(int idx)
    {
        if(tag2[idx]!=0)
        {
            info[idx*2] = tag2[idx];
            info[idx*2+1] = tag2[idx];

            tag2[idx*2] = tag2[idx];
            tag2[idx*2+1] = tag2[idx];

            tag1[idx*2] = 0;
            tag1[idx*2+1] = 0;

            tag2[idx] = 0;
        }
    }
    void push(int idx)
    {
        pushfix(idx);
        pushadd(idx);
/*
对于一个idx
如果加值的懒标记有值
修改的懒标记也有值
那么这个idx一定是先修改再加值的
如果是先加值在修改
在修改的时候
会把加值的懒标记变成0,那么加值的懒标记没有值违反条件
对于这个idx一定是先修改再加值的，如果先push加值再push修改就会出问题
*/
    }
    void modifyAdd(int idx,int l,int r,int st,int ed,int val)//l,r是搜寻区间，st,ed是目标区间
    {
        if(r<st||l>ed)
            return ;

        if(st<=l&&r<=ed)
        {
            tag1[idx] += val;
            info[idx] += val;
            return ;
        }
        push(idx);
        int mid = (l+r)/2;
        modifyAdd(idx*2,l,mid,st,ed,val);
        modifyAdd(idx*2+1,mid+1,r,st,ed,val);
        info[idx] = info[idx*2]+info[idx*2+1];
    }
    void modifyFix(int idx,int l,int r,int st,int ed,int val)
    {
        if(r<st||l>ed)
            return ;

        if(st<=l&&r<=ed)
        {
            tag2[idx] = val;
            info[idx] = val;
            tag1[idx] = 0;
            return ;
        }
        push(idx);
        int mid = (l+r)/2;
        modifyFix(idx*2,l,mid,st,ed,val);
        modifyFix(idx*2+1,mid+1,r,st,ed,val);
        info[idx] =info[idx*2]+info[idx*2+1];
    }
    int query(int idx,int l,int r,int st,int ed)
    {
        if(l>ed||r<st)
            return 0;

        if(st<=l&&r<=ed)
            return info[idx];

        push(idx);
        int mid = (l+r)/2;
        return query(idx*2,l,mid,st,ed)+query(idx*2+1,mid+1,r,st,ed);
    }
};
void work()
{
    int n,m,q;cin>>n>>m>>q;

    vector<array<int,3>> row(n+1);
    SegmentTree add(vector<int>(m+1),m+1),ti(vector<int>(m+1),m+1);
    vector<array<int,4>> Q(q+1);
    vector<int> lsr_x(n+1);
    vector<array<int,2>> nx_i[q+1];
    vector<int> sum(q+1);
    for(int i=1;i<=q;i++)
    {
        cin>>Q[i][0];
        if(Q[i][0] == 1)
        {
            cin>>Q[i][1]>>Q[i][2]>>Q[i][3];
        }
        else if( Q[i][0] == 2)
        {
            cin>>Q[i][1]>>Q[i][2];
            Q[i][3] = 0;
            lsr_x[Q[i][1]] = i;
        }
        else
        {
            cin>>Q[i][1]>>Q[i][2];
            Q[i][3] = 0;
            nx_i[lsr_x[Q[i][1]]].push_back({i,Q[i][2]});
        }
    }
    for(int i=1;i<=q;i++)
    {
        int op = Q[i][0];
        if(op == 1)
        {
            auto [op,l,r,x] = Q[i];
            add.modifyAdd(1,1,m,l,r,x);
            ti.modifyFix(1,1,m,l,r,i);
        }
        else if( op == 2)
        {
            auto [op,j,x,nothing] = Q[i];
            row[j] = {x,i};
            for(auto &[j,y]:nx_i[i])
            {
                sum[j] = add.query(1,1,m,y,y);
            }
        }
        else
        {
            auto [op,x,y,nothing] = Q[i];
            if(ti.query(1,1,m,y,y) > row[x][1])
            {
                cout<<row[x][0] + add.query(1,1,m,y,y) - sum[i]<<"\n";
            }
            else
            {
                cout<<row[x][0]<<"\n";
            }
        }
    }
    // cout<<1;
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