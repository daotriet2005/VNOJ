#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,pair<ll,ll> >data;
typedef pair<ll, string> super;
#define fore(i,a,b) for (ll i=a;i<=b;i++)
#define forw(i,a,b) for (ll i=a;i>=b;i--)
#define fast {ios::sync_with_stdio(false); cin.tie(0); }
#define fi first
#define se second
#define pu push
#define puf push_front
#define pub push_back
#define pof pop_front
#define pob pop_back
#define fr front
const ll oo=1e18;
const ll MOD=1e9+7;
map<ll,ll> save;
ll n,x,k,ans;
int main()
{
    fast;
    cin>>n>>k;
    fore(i,1,n)
    {
        cin>>x;
        for(ll j=1;j*j<=x;j++)
        if (x%j==0)
        {
            save[x/j]++;
            save[j]++;
            if (save[x/j]>=k) ans=max(ans,x/j);
            if (save[j]>=k) ans=max(ans,j);
        }
    }
    cout<<ans;
    return 0;
}
