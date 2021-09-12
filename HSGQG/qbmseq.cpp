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
int main()
{
    fast;
    ll ans=1;
    vector<ll> p;
    p.pb(1);
    while (ans<1e8)
    {
        ans+=p.size()+1;
        p.pb(ans);
    }
    ll n,x,result;
    result=0;
    cin>>n;
    vector<ll> a(1e5),dp(1e5);
    a[0]=-oo;
    dp[0]=0;
    fore(i,1,n)
    {
        cin>>a[i];
        if (binary_search(p.begin(),p.end(),a[i]))
            if (a[i]>=a[i-1]) dp[i]=dp[i-1]+1;
            else dp[i]=1;
        result=max(dp[i],result);
    }
    cout<<result;
    return 0;
}
