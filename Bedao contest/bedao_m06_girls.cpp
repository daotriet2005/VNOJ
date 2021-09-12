#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> data;
typedef pair<int, pair<int, int> > pii;
#define forw(i,a,b) for (int i=a;i<=b;i++)
#define forb(i,a,b) for (int i=a;i>=b;i--)
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
const ll mod=1e9+7;
const ll maxN=1e6+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,0};
const ll base=31;
ll n,m,k,a[maxN],pre[maxN];
void solve()
{
    cin>>m>>n>>k;
    forw(i,1,m)
        cin>>a[i];
    sort(a+1,a+1+m);
    forw(i,1,m)
        pre[i]=pre[i-1]+a[i];
    ll ans=-2;
    forw(i,n,m)
    if (a[i]-a[i-n+1]<=k)
        ans=max(ans,pre[i]-pre[i-n]);
    cout<<ans<<endl;
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
