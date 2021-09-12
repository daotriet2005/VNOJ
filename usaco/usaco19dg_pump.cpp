// http://www.usaco.org/current/data/sol_pump_gold_dec19.html
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
const ll oo=1e8;
const ll mod=1e9;
const int base=31;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,0};
// custom
const ll maxN=1000+5;
////////
vector <pii> check[maxN];
ll n,m,dp[maxN];
ll dijk(ll minflow)
{
    priority_queue<data, vector <data> , greater<data> > p;
    forw(i,1,n) dp[i]=oo;
    p.pu({dp[1]=0,1});
    while (!p.empty())
    {
        ll u=p.top().se;
        ll val=p.top().fi;
        p.pop();
        if (u==n) return dp[n];
        if (val>dp[u]) continue;
        for(auto res:check[u])
        {
            ll flow=res.fi;
            ll cost=res.se.fi;
            ll v=res.se.se;
            if (flow<minflow) continue;
            if (val+cost<dp[v])
            {
                p.pu({dp[v]=val+cost,v});
            }
        }
    }
    return dp[n];
}
void solve()
{
    cin>>n>>m;
    priority_queue<ll, vector <ll> , greater<ll> > p;
    forw(i,1,m)
    {
        ll u,v,flow,cost;
        cin>>u>>v>>cost>>flow;
        check[u].pb({flow,{cost,v}});
        check[v].pb({flow,{cost,u}});
        p.pu(flow);
    }
    double ans=0;
    ll minflow=-1,sum;
    while (!p.empty())
    {
        if (p.top()==minflow)
        {
            p.pop();
            continue;
        }
        minflow=p.top();
        sum=dijk(minflow);
        p.pop();
        ans=max(ans,(double)minflow/sum);
    }
    cout<<(ll)(ans*1000000)<<endl;
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
