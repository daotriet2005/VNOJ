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
ll a[105],n,m,dp[1000000];
int main()
{
    fast;
    cin>>n>>m;
    fore(i,1,n) cin>>a[i];
    sort(a+1,a+1+n,greater<ll>());
    int res=(m-100000)/a[1];
    m-=res*a[1];
    fore(i,0,m) dp[i]=oo;
    dp[0]=0;
    fore(i,1,n)
        fore(j,a[i],m)
        if (dp[j-a[i]]!=oo)
            dp[j]=min(dp[j],dp[j-a[i]]+1);
    cout<<dp[m]+res;
    return 0;
}
