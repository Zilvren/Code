#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int n,x,y;cin>>n>>x>>y;

    vector<int> lg(n+1);
    for(int i=2;i<=n;i++)
        lg[i] = lg[i/2] + 1;

    vector<vector<int>> Max(n+1,vector<int>(lg[n]+1));

    vector<vector<int>> Min(n+1,vector<int>(lg[n]+1,lnf));
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i],Max[i][0] = a[i];

    for(int len = 1;len<=lg[n];len++)
        for(int i=1;i + (1<<(len-1))<=n;i++)
            Max[i][len] = max(Max[i][len-1],Max[i + (1<<(len-1))][len-1]);

    auto get_Max = [&](int l,int r)
    {
        int len = lg[r-l+1];
        return max(Max[l][len] ,Max[r - (1<<(len)) + 1][len]);
    };

    for(int i=1;i<=n;i++)
        Min[i][0] = a[i];

    for(int len = 1;len<=lg[n];len++)
        for(int i=1;i + (1<<(len-1))<=n;i++)
            Min[i][len] = min(Min[i][len-1],Min[i + (1<<(len-1))][len-1]);

    auto get_Min = [&](int l,int r)
    {
        int len = lg[r-l+1];
        return min(Min[l][len] ,Min[r - (1<<(len)) + 1][len]);
    };
    int ans = 0;
    auto findl = [&](int l,int r,bool f)
    {
        int low = n+1;
        int st = l;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(f)
            {
                if(get_Max(st,mid)>=x)
                    r = mid-1,low = mid;
                else
                    l = mid+1;
            }
            else
            {
                if(get_Min(st,mid)<=y)
                    r = mid-1,low = mid;
                else
                    l = mid+1;
            }

        }

        return low;
    };
    auto findr = [&](int l,int r,bool f)
    {
        int high = 0;
        int st = l;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(f)
            {
                if(get_Max(st,mid)>x)
                    r = mid-1;
                else
                    l = mid+1,high = mid;
            }
            else
            {
                if(get_Min(st,mid)<y)
                    r = mid-1;
                else
                    l = mid+1,high = mid;
            }
        }
        return high;
    };
    for(int i=1;i<=n;i++)
    {
        int lm = findl(i,n,1);
        int rm = findr(i,n,1);
        int li = findl(i,n,0);
        int ri = findr(i,n,0);


        if(ri<li||rm<lm||get_Min(li,ri)!=y||get_Max(lm,rm)!=x)continue;

        if(rm < ri)
            swap(rm,ri),swap(lm,li);
        if(ri<lm)continue;

        if(li<lm)
        {
            ans += ri - lm+1;
        }
        else if(li>=lm)
        {
            ans += ri -li+1;
        }
    }
    cout<<ans<<"\n";

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