#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> data;
typedef pair<ll, pair<ll, ll> > pii;
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
const ll maxN=2000+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,0};
const ll base=31;
ll a[maxN],n,k,dp[maxN];
bool check(ll x)
{
    ll ans=oo;
    forw(i,1,n)
    {
        dp[i]=i-1;
        forb(j,i-1,1)
        {
            ll max1=a[i]+x*(i-j);
            ll min1=a[i]-x*(i-j);
            if (min1<=a[j] && a[j]<=max1)
                dp[i]=min(dp[i],dp[j]+(i-j-1));
        }
        ans=min(ans,dp[i]+n-i);
    }
    return ans<=k;
}
void solve()
{
    cin>>n>>k;
    forw(i,1,n)
        cin>>a[i];
    ll l=0;
    ll r=2e9;
    ll ans=0;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
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
