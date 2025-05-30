#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work2() {
    string s;cin>>s;

    int p = s.size()-1;
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i] != '0')
        {
            p = i;
            break;
        }
    }
    int cnt = 0;
    for(int i=0;i<p;i++)
    {
        if(s[i]!='0')
            cnt++;
    }
    cout<<cnt + s.size() - p - 1<<"\n";
}
void work()
{
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> fq;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        fq[a[i]]++;
    }
    auto Mex = [&]() -> int
    {
        int mx = 0;
        while (fq.count(mx))
            mx++;
        return mx;
    };
    int mg = Mex();
    vector<int> mfq(mg + 1, 0);
    if (mg > 0)
    {
        mfq[1] = fq[0];
        for (int x = 2; x <= mg; x++)
            mfq[x] = min(mfq[x - 1], fq[x - 1]);
    }
    int l = 0, r = mg;
    int ans = 0;
    function<bool(int)> check = [&](int x) -> bool
    {
        if (x == 0)
            return k <= n;

        if (mfq[x] < k)
            return false;

        unordered_map<int, int> now;
        int have = 0;
        int sc = 0;
        for (int t: a)
        {
            if (t >= 0 && t < x)
            {
                if (now[t] == 0)
                    have++;
                now[t]++;
            }
            if (have == x)
            {
                sc++;
                now.clear();
                have = 0;
            }
        }
        return sc >= k;
    };
    while (l <= r)
    {
        int mid = (l + r) / 2;
        bool f;
        if (mid > mg)
            f = false;
        else if (mid == 0)
            f = check(mid);
        else
        {
            if (mfq[mid] >= k)
                f = check(mid);
            else
                f = false;
        }
        if (f)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;

    }
    cout << ans << "\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t=1;
    cin>>t;
    while(t--)
    {
        work();
    }
}