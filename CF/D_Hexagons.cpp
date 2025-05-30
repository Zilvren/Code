#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int x,y;cin>>y>>x;

    int ru,r,d,ld,l,u;
    cin>>ru>>r>>d>>ld>>l>>u;
    int ans = lnf;
    if(x>=0&&y>=0)
    {
        ans = min({ y*u + r*x,
                    ru*y + ((y>=x)?(y - x)*l:(x - y)*r),
                    ru*x + ((y>=x)?(y - x)*u:(x - y)*d)});
    }
    else if(x<=0&&y<=0)
    {
        x = -x,y = -y;
        ans = min({ y*d + l*x,
                    ld*y + ((y>=x)?(y - x)*r:(x - y)*l),
                    ld*x + ((y>=x)?(y - x)*d:(x - y)*u)});
    }
    else if(x<=0&&y>=0)
    {
        ans = min({ y*u + l*(-x),
                    l*(y-x) + ru*y,
                    u*(y-x) + ld*(-x)});
    }
    else if(x>=0&&y<=0)
    {
        ans = min({ (-y)*d + r*x,
                    r*(x-y) + ld*(-y),
                    d*(x-y) + ru*(x)});
    }
    cout<<ans<<"\n";
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