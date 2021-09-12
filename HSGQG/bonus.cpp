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
ll n,k,dp[1005][1005],ans,x;
ll tinh(int x,int y)
{
    return dp[x][y]-dp[x-k][y]-dp[x][y-k]+dp[x-k][y-k];
}
int main()
{
    fast;
    cin>>n>>k;
    fore(i,1,n)
    {
        ll res=0;
        fore(j,1,n)
        {
            cin>>x;
            res+=x;
            dp[i][j]=dp[i-1][j]+res;
        }
    }
    fore(i,k,n)
        fore(j,k,n)
            ans=max(ans,tinh(i,j));
    cout<<ans;
    return 0;
}
