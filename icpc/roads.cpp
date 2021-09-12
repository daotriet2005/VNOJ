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
const ll maxN=100+5;
////////
ll l[maxN][maxN],c[maxN][maxN],n,m,k,dp[maxN][10005];
vector <pii> check[maxN];
void dijk()
{
    forw(i,1,n)
        forw(j,0,k) dp[i][j]=oo;
    priority_queue<pii, vector <pii>, greater<pii> > p;
    dp[1][0]=0;
    p.pu({0,{1,0}});
    while (!p.empty())
    {
        ll length=p.top().fi;
        ll u=p.top().se.fi;
        ll cost=p.top().se.se;
        p.pop();
        if (u==n)
        {
            cout<<length<<endl;
            return;
        }
        if (length>dp[u][cost]) continue;
        for(auto res:check[u])
        {
            ll v=res.fi;
            ll le=res.se.fi;
            ll val=res.se.se;
            if (cost+val<=k && length+le<dp[v][cost+val])
            {
                dp[v][cost+val]=length+le;
                p.pu({dp[v][cost+val],{v,cost+val}});
            }
        }
    }
    cout<<-1<<endl;
}
void solve()
{
    cin>>k>>n>>m;
    forw(i,1,n) check[i].clear();
    forw(i,1,n)
        forw(j,1,n)
            l[i][j]=c[i][j]=oo;
    forw(i,1,m)
    {
        ll u,v,x,y;
        cin>>u>>v;
        cin>>x>>y;
        check[u].pb({v,{x,y}});
    }
    dijk();
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
