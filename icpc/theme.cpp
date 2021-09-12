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
ll n,dp[5005][5005],a[5005],out;
int main()
{
    fast;
    cin>>n;
    fore(i,1,n) cin>>a[i];
    fore(i,4,n)
        fore(j,2,n-2)
            if (a[i]-a[i-1]==a[j]-a[j-1])
            {
                dp[i][j]=min(dp[i-1][j-1]+1,i-j-1);
                out=max(out,dp[i][j]);
            }
    if (out>=4)cout<<out+1;
    else cout <<0;
    return 0;
}
