#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> data;
#define fore(i,a,b) for (ll i=a;i<=b;++i)
#define forw(i,a,b) for (ll i=a;i>=b;i--)
#define fast {ios::sync_with_stdio(false); cin.tie(0); }
#define fi first
#define se second
#define pu push
#define pb push_back
#define fr front
const ll oo=1e18;
const ll MOD=1e9+7;
ll n,p,ans,res,count1,a[50005],dp[50005],min1[50005],pos,x;
ll bs(int l, int r, ll x)
{
    ll ans=-1;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (x-min1[mid]>=p)
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}
int main()
{
    fast;
    cin>>n>>p;
    fore(i,1,n)
    {
        cin>>x;
        dp[i]=dp[i-1]+x;
        ll vitri=bs(0,i-1,dp[i]);
        if (vitri!=-1)
            ans=max(ans,i-vitri);
        min1[i]=min(min1[i-1],dp[i]);
    }
    if (!ans) cout<<-1;
    else cout<<ans;
    return 0;
}
