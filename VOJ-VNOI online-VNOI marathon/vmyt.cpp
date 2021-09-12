#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, string> super;
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
const ll oo=1e18;
const ll MOD=1e9+7;
const ll maxN=2e5+5;
ll k;
struct data
{
    ll a[100][100];
};
data multiply(data a, data b)
{
    data ans;
    fore(i,1,k)
        fore(j,1,k)
        {
            ans.a[i][j]=0;
            fore(p,1,k)
                ans.a[i][j]=(ans.a[i][j]+(a.a[i][p]*b.a[p][j])%(MOD-1))%(MOD-1);
        }
    return ans;
}
data power(data a, ll n)
{
    data ans;
    fore(i,1,k)
        fore(j,1,k) ans.a[i][j]=0;
    fore(i,1,k) ans.a[i][i]=1;
    while (n>0)
    {
        if (n%2) ans=multiply(ans,a);
        n/=2;
        a=multiply(a,a);
    }
    return ans;
}
ll binpow(ll x, ll y)
{
    ll ans=1;
    while (y>0)
    {
        if (y%2) ans=(ans*x)%MOD;
        y/=2;
        x=(x*x)%MOD;
    }
    return ans;
}
int main()
{
    fast;
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    ll n;
    cin>>n>>k;
    vector <ll> dp(k+5,1);
    fore(i,1,k) cin>>dp[i];
    data a;
    fore(i,1,k)
        fore(j,1,k) a.a[i][j]=0;
    fore(i,2,k) a.a[i][i-1]=1;
    fore(i,1,k) a.a[i][k]=1;
    data b=power(a,n-k);
    vector <ll> new_dp(k+5,1);
    fore(j,k,k)
    {
        fore(i,1,k)
            new_dp[j]=(new_dp[j]*binpow(dp[i],b.a[i][j]))%MOD;
    }
    cout<<new_dp[k];
    return 0;
}
