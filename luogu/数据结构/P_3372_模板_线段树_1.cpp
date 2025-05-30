#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;
struct SegmentTree
{
    vector<int> info,tag,a;
    SegmentTree(vector<int> a,int n):info(4*n+1),tag(4*n+1),a(a){}

    void BuildTree(int idx,int l,int r)
    {
        if(l==r)
        {
            info[idx] = a[l];
            return ;
        }

        int mid = (l+r)/2;
        BuildTree(idx*2,l,mid);
        BuildTree(idx*2+1,mid+1,r);
        info[idx] = info[idx*2] + info[idx*2+1];
    }
    void push(int idx,int l,int r)
    {
        int mid = (l+r)/2;

        info[idx*2] += (mid-l+1)*tag[idx];
        info[idx*2+1] += (r-mid)*tag[idx];
        tag[idx*2] += tag[idx];
        tag[idx*2+1] += tag[idx];

        tag[idx] = 0;
    }
    void modify(int idx,int l,int r,int st,int ed,int val)
    {
        if(r<st||l>ed)
            return ;
        if(st<=l&&r<=ed)
        {
            info[idx] += (r-l+1)*val;
            tag[idx] += val;
            return ;
        }
        push(idx,l,r);
        int mid = (l+r)/2;
        modify(idx*2,l,mid,st,ed,val);
        modify(idx*2+1,mid+1,r,st,ed,val);
        info[idx] = info[idx*2] + info[idx*2+1];
    }
    int query(int idx,int l,int r,int st,int ed)
    {
        if(r<st||l>ed)
            return 0;
        if(st<=l&&r<=ed)
        {
            return info[idx];
        }
        push(idx,l,r);
        int mid = (l+r)/2;
        return query(idx*2,l,mid,st,ed) + query(idx*2+1,mid+1,r,st,ed);
    }
};
void work()
{
    int n,q;cin>>n>>q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    SegmentTree tr(a,n);
    tr.BuildTree(1,1,n);
    while(q--)
    {
        int op;cin>>op;
        if(op == 1)
        {
            int l,r,k;cin>>l>>r>>k;
            tr.modify(1,1,n,l,r,k);
        }
        else
        {
            int l,r;cin>>l>>r;
            cout<<tr.query(1,1,n,l,r)<<"\n";
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