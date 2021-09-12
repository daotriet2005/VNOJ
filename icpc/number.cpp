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
const ll oo=1e18;
const ll mod=1e9+7;
const ll maxN=1e4+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,0};
const ll base=31;
int n,m,t;
vector <int> check[maxN];
bool go[maxN],vis[maxN];
vector< int> save;
void topo(int u)
{
    vis[u]=true;
    for(int v:check[u])
        if (!vis[v])
            topo(v);
    save.pb(u);
}
void dfs(int u)
{
    go[u]=true;
    for(int v:check[u])
        if (!go[v])
            dfs(v);
}
void solve()
{
    cin>>n>>m>>t;
    forw(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        if (u==t) continue;
        check[v].pb(u);
    }
    forw(i,1,n)
    if (!vis[i])
        topo(i);
    int ans=0;
    forb(i,save.size()-1,0)
    if (!go[save[i]])
    {
        ans++;
        dfs(save[i]);
    }
    cout<<ans-1<<endl;
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
