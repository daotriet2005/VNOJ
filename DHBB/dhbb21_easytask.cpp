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
const int base=31;
const ll maxN=1e6+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
const int maxd=10000;
const int limit=1e5+1;
ll ans,fen[maxN],pre[maxN],x,n;
bool notprime[maxN];
void sieve()
{
    notprime[1]=true;
    for(ll i=2;i<=n;i++)
    if (!notprime[i])
        for(ll j=i*i;j<=n;j+=i) notprime[j]=true;
    return;
}
void update(int pos, ll val)
{
    for(;pos<=n;pos+=(pos & -pos))
        fen[pos]=min(fen[pos],val);
    return;
}
ll getmin(int pos)
{
    ll ans=oo;
    for(;pos>0;pos-=(pos & -pos))
        ans=min(ans,fen[pos]);
    return ans;
}
void solve()
{
    cin>>n;
    sieve();
    forw(i,1,n) fen[i]=oo;
    ans=-oo;
    forw(i,1,n)
    {
        cin>>x;
        pre[i]=pre[i-1]+x;
        if (!notprime[i])
            ans=max(ans,pre[i]-getmin(n));
        if (!notprime[i+1])
                update(i,pre[i]);
    }
    cout<<ans<<endl;
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
