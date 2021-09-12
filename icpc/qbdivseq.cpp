#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;
#define fore(i,a,b) for (ll i=a;i<=b;i++)
#define forw(i,a,b) for (ll i=a;i>=b;i--)
#define fast {ios::sync_with_stdio(false); cin.tie(0); }
#define fi first
#define se second
#define pu push
#define pb push_back
const ll oo=1e18;
const ll MOD=1e9+7;
int main()
{
    fast;
    int n;
    cin>>n;
    multiset<int,greater<int> > p;
    fore(i,1,n)
    {
        int x;
        cin>>x;
        if (!p.empty())
        {
        auto it=p.lower_bound(x);
        if (it!=p.end())
        p.erase(it);
        //p.insert(x);
        }
        p.insert(x);
        //for(auto it=p.begin();it!=p.end();++it)
        //    cout<<(*it)<<" ";
        //cout<<endl;
    }
    cout<<p.size();
    return 0;
}
