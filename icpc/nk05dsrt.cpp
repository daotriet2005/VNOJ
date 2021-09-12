// idea: dp[i] = luong nuoc nho nhat de di tu i -> n
// in case you need:
// https://acceptedcode.blogspot.com/2016/08/nk05dsrt-sa-mac.html
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> data;
typedef pair<ll, pair<ll, ll> > pii;
typedef vector <ll> vi;
#define forw(i,a,b) for (ll i=a;i<=(b);i++)
#define forb(i,a,b) for (ll i=a;i>=(b);i--)
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
const ll mod=1e9;
const int base=31;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,0};
// custom
const ll maxN=4e6+5;
ll dp[105],n,m,c,u,v,z;
vector <data> check[105];
ll take(ll c, ll l, ll val)
{
    // (c-l) + (c-2*l)*times >=val
    // => (c-2*l)*times >= val-c+l
    // => find times
    if (val+l<=c) return 0;
    ll a=val-c+l;
    ll b=c-2*l;
    if (b<=0) return oo;
    return a/b+(a%b!=0);

}
void solve()
{
    cin>>n>>m>>c;
    forw(i,1,n) check[i].clear();
    forw(i,1,m)
    {
        cin>>u>>v>>z;
        check[u].pb({z,v});
        check[v].pb({z,u});
    }
    forw(i,1,n) dp[i]=oo;
    dp[n]=0;
    priority_queue<data, vector <data>, greater<data> > p;
    p.pu({0,n});
    while (!p.empty())
    {
        ll val=p.top().fi;
        ll u=p.top().se;
        p.pop();
        if (val>dp[u]) continue;
        for(auto res:check[u])
        {
            ll l=res.fi;
            ll v=res.se;
            ll k=take(c,l,val);
            // dp[i] là lượng nước nhỏ nhất cần để từ i đến n
            // k là số lần đi từ v đến i rồi i quay về v để lấy thêm nước => số nược lấy thêm là c-2*l
            // luôn mặc định là 1 lần đi từ v đến i => c-l
            // gộp từ 2 trên ta có (c-l) + (c-2*l)*k >=val => chi phí là (2*k+1)*l + val
            // TH val + l <= c => k=0
            // TH c<2*l => impossible
            if (k!=oo && val+(k*2+1)*l<dp[v])
                p.pu({dp[v]=val+(k*2+1)*l,v});
        }
    }
    cout<<dp[1]<<endl;
}
int main()
{
    fast;
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    ll t=1; cin>>t;
    while (t--) solve();
    return 0;
}
