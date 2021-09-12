#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pi;
typedef pair<ll, pair<ll, ll> > pii;
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
const ll mod=1e9+7;
const int base=31;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
// custom
const ll maxN=1e4+5;
/////
ll dp[maxN][4],n,m,k,s,t;
vector <pi> check[maxN][4];
void dijk(int s, int i)
{
    forw(j,1,n)
        dp[j][i]=oo;
    priority_queue<pi,vector <pi>, greater<pi> > p;
    dp[s][i]=0;
    p.pu({0,s});
    while (!p.empty())
    {
        ll val=p.top().fi;
        ll u=p.top().se;
        p.pop();
        if (val>dp[u][i]) continue;
        for(auto res:check[u][i])
        {
            ll cost=res.fi;
            ll v=res.se;
            if (val+cost<dp[v][i])
            {
                dp[v][i]=val+cost;
                p.pu({val+cost,v});
            }
        }
    }
    return;
}
void solve()
{
    cin>>n>>m>>k>>s>>t;
    forw(i,1,n)
    {
        check[i][1].clear();
        check[i][2].clear();
    }
    forw(i,1,m)
    {
        ll u,v,c;
        cin>>u>>v>>c;
        check[u][1].pb({c,v});
        check[v][2].pb({c,u});
    }
    dijk(s,1);
    dijk(t,2);
    ll ans=dp[t][1];
    forw(i,1,k)
    {
        ll u,v,c;
        cin>>u>>v>>c;
        if (dp[u][1]!=oo && dp[v][2]!=oo) ans=min(ans,dp[u][1]+dp[v][2]+c);
        if (dp[v][1]!=oo && dp[u][2]!=oo) ans=min(ans,dp[v][1]+dp[u][2]+c);
    }
    if (ans==oo) cout<<-1<<endl;
    else cout<<ans<<endl;
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
