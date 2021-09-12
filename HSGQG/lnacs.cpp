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
#define fr front
const ll oo=1e18;
const ll MOD=1e9+7;
ll dp[1005][1005],n,m,a[1005],b[1005];
int main()
{
    fast;
    cin>>n>>m;
    fore(i,1,n) cin>>a[i];
    fore(i,1,m) cin>>b[i];
    fore(i,1,n)
        fore(j,1,m)
            if (a[i]==b[j]) dp[i+1][j+1]=dp[i-1][j-1]+1;
            else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
    cout<<dp[n+1][m+1];
    return 0;
}
