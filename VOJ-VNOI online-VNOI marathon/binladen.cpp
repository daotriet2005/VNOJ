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
const ll oo=1e18;
const ll mod=1e9;
const int base=31;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,0};
// custom
const ll maxN=3e4+5;
////////
bool vis[2500][15];
ll dp[2500][15],n,m;
vector <pii> check[2500][15];
void dijk()
{
    forw(i,1,n)
        forw(j,1,m) dp[i][j]=oo;
    priority_queue<pii, vector <pii>, greater<pii> > p;
    forw(i,1,m)
        p.pu({0,{0,i}});
    while (!p.empty())
    {
        ll val=p.top().fi;
        ll x=p.top().se.fi;
        ll y=p.top().se.se;
        p.pop();
        if (vis[x][y]) continue;
        vis[x][y]=true;
        for(auto res:check[x][y])
        {
            ll dodai=res.fi;
            ll x2=res.se.fi;
            ll y2=res.se.se;
            if (!vis[x2][y2] && dodai+val<dp[x2][y2])
            {
                dp[x2][y2]=val+dodai;
                p.pu({dp[x2][y2],{x2,y2}});
            }
        }
    }
}
void solve()
{
    cin>>n>>m;
    forw(i,0,2*n-1) // level= i/2+1
    {
        ll x;
        if (i%2==0)
            forw(j,1,m)
            {
                cin>>x;
                check[i/2][j].pb({x,{i/2+1,j}});
                check[i/2+1][j].pb({x,{i/2,j}});
            }
        else
            forw(j,1,m-1)
            {
                cin>>x;
                check[i/2+1][j].pb({x,{i/2+1,j+1}});
                check[i/2+1][j+1].pb({x,{i/2+1,j}});
            }
    }
    dijk();
    cout<<dp[n][m];
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
