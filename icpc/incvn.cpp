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
const ll oo=1e14;
const ll mod=5000000;
const ll maxN=3e4+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
const ll base=31;
const int maxd=10000;
const int limit=1e5+1;
ll fen[limit+5][55],n,k,x;
ll get(int pos, int k)
{
    ll ans=0;
    for(;pos>0;pos-=(pos & -pos))
        ans=(ans+fen[pos][k])%mod;
    return ans;
}
void update(int pos, int k, ll val)
{
    for(;pos<=limit;pos+=(pos & -pos))
        fen[pos][k]=(fen[pos][k]+val)%mod;
    return;
}
void solve()
{
    cin>>n>>k;
    forw(i,1,n)
    {
        cin>>x;
        x++;
        forw(j,2,k)
        {
            ll p=get(x-1,j-1);
            update(x,j,p);
        }
        update(x,1,1);
    }
    cout<<get(limit,k)<<endl;
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
