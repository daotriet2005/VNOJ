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
const ll oo=1e18;
const ll mod=5000000;
const ll maxN=1e5+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
const ll base=31;
const int maxd=10000;
const int limit=1e5+1;
ll dp[105][105],n,m,a[105][105],ans;
void solve()
{
    cin>>n>>m;
    forw(i,1,n)
        forw(j,1,m)
            cin>>a[i][j];
    forw(j,1,m)
        forw(i,1,n)
        if (j==1) dp[i][j]=a[i][j];
        else
        {
            dp[i][j]=dp[i][j-1]+a[i][j];
            if (i>1) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+a[i][j]);
            if (i<n) dp[i][j]=max(dp[i][j],dp[i+1][j-1]+a[i][j]);
        }
    ans=-oo;
    forw(i,1,n)
        ans=max(ans,dp[i][m]);
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
