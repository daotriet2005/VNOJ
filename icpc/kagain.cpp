#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> data;
typedef pair<ll, string> super;
#define fore(i,a,b) for (ll i=a;i<=b;++i)
#define forw(i,a,b) for (ll i=a;i>=b;i--)
#define fast {ios::sync_with_stdio(false); cin.tie(0); }
#define fi first
#define se second
#define pu push
#define puf push_front
#define pub push_back
#define pof pop_front
#define pob pop_back
#define fr front
const ll oo=1e18;
const ll MOD=1e9+7;
data save[30005];
ll a[30005],n;
void solve()
{
    cin>>n;
    deque<ll> p;
    fore(i,1,n)
    {
        cin>>a[i];
        save[i].fi=i;
        while (!p.empty() && a[p.back()]>=a[i])
        {
            save[p.back()].se=i-1;
            save[i].fi=save[p.back()].fi;
            p.pob();
        }
        p.pub(i);
    }
    while (!p.empty())
    {
        save[p.back()].se=n;
        p.pob();
    }
    ll max1=0;
    fore(i,1,n)
        max1=max(max1,(save[i].se-save[i].fi+1)*a[i]);
    fore(i,1,n)
    if (max1==(save[i].se-save[i].fi+1)*a[i])
    {
        cout<<max1<<" "<<save[i].fi<<" "<<save[i].se<<endl;
        return;
    }
}
int main()
{
    fast;
    int t;
    cin>>t ;
    while(t--) solve();
    return 0;
}
