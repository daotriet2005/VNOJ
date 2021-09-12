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
ll n,x,max1,max2;
int main()
{
    fast;
    cin>>n;
    ll max1=0;
    ll max2=0;
    fore(i,1,n)
    {
        cin>>x;
        ll res1=max(max2+x,max1);
        ll res2=max(max1-x,max2);
        max1=max(max1,res1);
        max2=max(max2,res2);
    }
    cout<<max(max1,max2);
    return 0;
}
