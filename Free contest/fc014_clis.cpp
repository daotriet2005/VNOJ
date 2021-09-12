#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> data;
typedef pair<ll, pair<ll, ll> > pii;
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
const ll oo=1e18;
const ll mod=1e9;
const int base=31;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
// custom
const ll maxN=1505;
/////
void solve()
{
    string s;
    cin>>s;
    vector <int> dp;
    for(auto res:s)
    {
        int pos=upper_bound(all(dp),res)-dp.begin();
        if (pos==dp.size()) dp.pb(res);
        else dp[pos]=res;
    }
    cout<<dp.size()<<endl;
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
