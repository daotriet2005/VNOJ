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
const ll maxN=1e6+5;
typedef pair<double, pair<ll, ll> > data;
typedef pair<double,ll> super;
/////
double dp[10005][25];
ll n,m,k;
vector <super> check[10005];
void dijk()
{
    // pair<double, pair <ll, ll> > : value - node - number of roads chose
    priority_queue< data, vector <data> , greater<data> > p;
    forw(i,1,n)
        forw(j,0,k)
            dp[i][j]=oo;
    dp[1][0]=0;
    p.pu({0,{1,0}});
    while (!p.empty())
    {
        double val=p.top().fi;
        ll u=p.top().se.fi;
        ll i=p.top().se.se;
        p.pop();
        if (val>dp[u][i]) continue;
        for(auto res:check[u])
        {
            double cost=res.fi;
            ll v=res.se;
            if (val+cost<dp[v][i])
            {
                dp[v][i]=val+cost;
                p.pu({val+cost,{v,i}});
            }
            forw(j,i+1,k)
            {
                cost/=2;
                if (val+ cost<dp[v][j])
                {
                    dp[v][j]=val+cost;
                    p.pu({val+cost,{v,j}});
                }
            }
        }
    }
    printf("%.2f \n",dp[n][k]);
    return;
}
void solve()
{
    cin>>n>>m>>k;
    forw(i,1,m)
    {
        ll u,v; double c;
        cin>>u>>v>>c;
        check[u].pb({c,v});
        check[v].pb({c,u});
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
