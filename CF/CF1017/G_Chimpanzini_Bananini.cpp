#include<bits/stdc++.h>
#define int long long
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 1e5+7;

void work()
{
    int q;cin>>q;

    deque<int> Q;
    int s1 = 0,s2 = 0;
    int s = 0;
    int n = 0;
    bool f = 0;
    //f == 0表示在back
    //f == 1表示在front
    while(q--)
    {
        int op;cin>>op;
        if(op == 1)
        {
            s1 += s - n*(f == 0?Q.back():Q.front());
            s2 = s2 - s + n*(f == 0?Q.back():Q.front());
            if(!f)
            {
                Q.push_front(Q.back());
                Q.pop_back();
            }
            else
            {
                Q.push_back(Q.front());
                Q.pop_front();
            }
        }
        else if(op == 2)
        {
            swap(s1,s2);
            f = !f;
        }
        else if(op == 3)
        {
            n++;
            int k;cin>>k;
            s1 += k * n;
            s2 += s + k;
            s += k;
            if(!f)
                Q.push_back(k);
            else
                Q.push_front(k);
        }
        cout<<s1<<"\n";
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