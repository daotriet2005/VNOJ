#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> data;
#define forw(i,a,b) for (ll i=a;i<=b;i++)
#define forb(i,a,b) for (ll i=a;i>=b;i--)
#define fast {ios::sync_with_stdio(false); cin.tie(0); }
#define fi first
#define se second
#define pu push
#define puf push_front
#define pb push_back
#define pof pop_front
#define pob pop_back
#define fr front
#define all(a) a.begin(),a.end()
const ll oo=1e14;
const ll mod=1000001;
const ll maxN=3e5+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
const ll base=31;
ll n,x,res,ans;
vector <ll> a;
void solve()
{
    cin>>n>>x;
    forw(i,1,n)
    {
        cin>>res;
        int pos=upper_bound(all(a),x-res)-a.begin();
        ans+=pos;
        a.pb(res);
    }
    cout<<ans;
}
int main()
{
    fast;
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    ll t=1; //cin>>t;
    while (t--) solve();
    return 0;
}
