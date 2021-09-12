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
const ll mod=1e9+7;
const ll maxN=2e5+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
const ll base=31;
ll fen[maxN],n,k,pre[maxN],vitri[maxN];
vector <ll> save;
void update(ll pos, ll val)
{
    for(;pos<=n+1;pos+=(pos & -pos))
        fen[pos]+=val;
    return;
}
ll sum(ll pos)
{
    ll res=0;
    for(;pos>0;pos-=(pos & -pos))
        res+=fen[pos];
    return res;
}
bool check(ll x)
{
    ll res=0;
    memset(fen,0,sizeof fen);
    update(vitri[0],1);
    forw(i,1,n)
    {

        ll pos=lower_bound(all(save),pre[i]-x)-save.begin();
        ll p=sum(pos);
        update(vitri[i],1);
        res+=p;

    }
    return (res<k);
}
void solve()
{
    cin>>n>>k;
    forw(i,1,n)
    {
        ll x;
        cin>>x;
        pre[i]=pre[i-1]+x;
        save.pb(pre[i]);
    }
    save.pb(0);
    sort(all(save));
    forw(i,0,n)
        vitri[i]=lower_bound(all(save),pre[i])-save.begin()+1;
    ll l=-oo;
    ll r=oo;
    ll ans=0;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (check(mid)==true)
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
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
