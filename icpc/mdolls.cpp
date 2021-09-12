#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fore(i,a,b) for(int i=a;i<=b;i++)
#define pu push
typedef pair<int, int> data;
int t,n,out;
data a[20005];
bool comp(data a, data b)
{
    if (a.fi>b.fi) return false;
    if (a.fi==b.fi)
        if (a.se<b.se) return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while (t--)
    {
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i].fi>>a[i].se;
    sort(a+1,a+1+n);
    multiset<int> p;
    int res=0;
    stack<int> tmp;
    tmp.pu(a[1].se);
    fore(i,2,n)
    {
    if (a[i].fi==a[i-1].fi)
        if (res==0) tmp.pu(a[i].se);
        else
        {
        if (!p.empty())
            {
            auto it=p.lower_bound(a[i].se);
            if (it!=p.begin()) {
                --it;
                p.erase(it);
                }
            }
        tmp.pu(a[i].se);
        }
    else
    {
        res++;
        while (!tmp.empty())
        {
            p.insert(tmp.top());
            tmp.pop();
        }
        if (!p.empty())
        {
            auto it=p.lower_bound(a[i].se);
            if (it!=p.begin()) {
                --it;
                p.erase(it);
            }
        }
        tmp.pu(a[i].se);
    }
    }
    while (!tmp.empty())
    {
        p.insert(tmp.top());
        tmp.pop();
    }
    cout<<p.size()<<endl;
    }
    return 0;
}
