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
const ll maxN=100+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
const ll base=31;
int child[maxN],num[maxN],low[maxN],dem,ans,n,m;
vector <int> check[maxN];
void dfs(int u, int father)
{
    child[u]=1;
    num[u]=low[u]=++dem;
    for(int v:check[u])
    if (v!=father)
    {
        if (!num[v])
        {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            child[u]+=child[v];
            if  (low[v]>=num[v])
                ans+=child[v]*(n-child[v]);
        }
        else low[u]=min(low[u],num[v]);
    }
}
void solve()
{
    cin>>n>>m;
    forw(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        check[u].pb(v);
        check[v].pb(u);
    }
    dfs(1,1);
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
