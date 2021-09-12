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
const ll mod=1e9;
const int base=31;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
// custom
const ll maxN=1005;
/////
ll u[20005],v[20005],n,m,color[maxN];
list<int> check[maxN];
vector <pi> ans;
bool ok[maxN][maxN],have,skip[maxN][maxN];
void deep(int u)
{
    color[u]=1;
    for(int v:check[u])
    {
    if (have) return;
    if (!ok[u][v]) continue;
    if (!color[v]) deep(v);
    else
        if (color[v]==1)
            have=true;
    }
    color[u]=2;
}
void solve()
{
    cin>>n>>m;
    forw(i,1,m)
    {
        cin>>u[i]>>v[i];
        if (ok[u[i]][v[i]])
        {
            skip[u[i]][v[i]]=true;
            continue;
        }
        check[u[i]].pb(v[i]);
        ok[u[i]][v[i]]=true;
    }
    forw(i,1,n)
    if (!color[i] && !have) deep(i);
    if (!have)
    {
        cout<<-1; return;
    }
    forw(i,1,m)
    {
        if (skip[u[i]][v[i]]) continue;
        ok[u[i]][v[i]]=false;
        have=false;
        memset(color,0,sizeof color);
        forw(j,1,n)
        if (!color[j] && !have)
            deep(j);
        if (!have) ans.pb({u[i],v[i]});
        ok[u[i]][v[i]]=true;
    }
    sort(all(ans));
    cout<<ans.size()<<endl;
    for(auto res:ans)
        cout<<res.fi<<" "<<res.se<<endl;
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
