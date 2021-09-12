#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long int ll;
typedef pair<double,ll> data;
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
const ll maxN=1000+5;
////////
ll dp[maxN],n,m;
vector <int> check[maxN];
ll calc(ll val, int u, int v)
{
    ll length=abs(u-v);
    ll times=val/length;
    val%=length;
    ll level;
    if (times%2==0)
    {
        level=min(u,v)+val;
        if (u<v && level!=u)
            return v-level+length+length;
        else
            return u-level+length;
    }
    else
    {
        level=max(u,v)-val;
        if (u>v && level!=u)
            return level-u+length;
        else
            return level-v+length+length;
    }
}
void dijk()
{
    forw(i,1,n) dp[i]=oo;
    priority_queue<data, vector<data> , greater<data> > p;
    dp[1]=0;
    p.pu({0,1});
    while (!p.empty())
    {
        ll u=p.top().se;
        ll val=p.top().fi;
        p.pop();
        if (val>dp[u]) continue;
        for(ll v:check[u])
        {
            ll res=calc(val,u,v);
            //cout<<u<<" "<<v<<" "<<val<<" "<<res<<" "<<dp[v]<<endl;
            if (val+res<dp[v])
                p.pu({dp[v]=val+res,v});
        }
    }
    cout<<dp[n]*5<<endl;
}
void solve()
{
    cin>>n>>m;
    forw(i,1,m)
    {
        ll u,v;
        cin>>u>>v;
        check[u].pb(v);
        check[v].pb(u);
    }
    dijk();

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
