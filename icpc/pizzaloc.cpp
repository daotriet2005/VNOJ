#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> data;
#define fore(i,a,b) for (ll i=a;i<=b;i++)
#define forw(i,a,b) for (ll i=a;i>=b;i--)
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
const ll maxN = 2e5+5;
const ll oo = 1e18;
const ll mod=1e9+7;
struct toado
{
    int x,y,z;
};
toado a[25],b[105];
int save[105],n,m,k,r;
bool ok(toado a, toado b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)<=r*r;
}
void setup()
{
    fore(i,0,m-1)
        fore(j,0,n-1)
            if (ok(a[i],b[j]))
                save[j]|=(1<<i);
}
void solve()
{
    cin>>k>>r;
    cin>>m;
    fore(i,0,m-1) cin>>a[i].x>>a[i].y;
    cin>>n;
    fore(i,0,n-1) cin>>b[i].x>>b[i].y>>b[i].z;
    setup();
    ll ans=0;
    fore(mask,(1<<k)-1,(1<<m)-1)
    if (__builtin_popcount(mask)==k)
    {
        ll res=0;
        fore(i,0,n-1)
        if (save[i]&mask)
            res+=b[i].z;
        ans=max(ans,res);
    }
    cout<<ans;
    return;
}
int main()
{
    fast;
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    int t; t=1;
    //cin>>t;
    while (t--) solve();
    return 0;
}
