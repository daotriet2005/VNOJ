#include <bits/stdc++.h>
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
const ll oo=1e18;
const ll MOD=1e9+7;
const ll maxN=300005;
data save[maxN];
struct super
{
    ll a,b,z;
};
super dp[maxN];
ll n,a,b;
void solve()
{
    cin>>n>>a>>b;
    forw(i,1,n)
        cin>>save[i].fi>>save[i].se;
    sort(save+1,save+1+n);
    forw(i,1,n)
    {
        dp[i]=dp[i-1];
        dp[i].z=save[i].fi;
        if (save[i].se==1) dp[i].a++;
        else dp[i].b++;
    }
    int l=0;
    ll ans=oo;
    forw(r,1,n)
    {
        while (dp[r].a-dp[l+1].a>=a && dp[r].b-dp[l+1].b>=b && l<r-1) l++;
        if (dp[r].a-dp[l].a>=a && dp[r].b-dp[l].b>=b)
            ans=min(ans,dp[r].z-dp[l+1].z);
    }
    if (ans==oo) cout<<-1;
    else cout<<ans;
}
int main()
{
    fast;
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    int t=1; //cin>>t;
    while (t--)
        solve();
    return 0;
}
