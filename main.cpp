#include<bits/stdc++.h>

using namespace std;
void work()
{
    int n,m;cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    while(1)
    {
        int x = a[1];
        vector<int> t(1);
        for(int i=1;i<=n;i++)
        {
            if(a[i]<=x)
                t.push_back(a[i]);
        }
        int p = t.size() - 1;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>x)
                t.push_back(a[i]);
        }
        if(p == m)
        {
            cout<<"\n";
            cout<<t[p];
            break;
        }
        else
        cout<<t[p]<<" ";
        a = t;
    }
}
signed main()
{
//	int t;cin>>t;
//	while(t--)
    work();

}