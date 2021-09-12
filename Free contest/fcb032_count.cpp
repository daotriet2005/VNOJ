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
const ll maxN=2e5+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
const ll base=31;
set<int> save[maxN];
int n,m,ans[maxN];
vector <int> check[maxN];
bool vis[maxN];
void dfs(int u)
{
    vis[u]=true;
    for(int v:check[u])
    if (!vis[v])
    {
        dfs(v);
        if (save[v].size()>save[u].size()) swap(save[u],save[v]);
        for(auto x:save[v])
            save[u].insert(x);
        save[v].clear();
    }
    ans[u]=save[u].size();
}
void solve()
{
    cin>>n;
    forw(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        check[u].pb(v);
        check[v].pb(u);
    }
    forw(i,1,n)
    {
        int x;
        cin>>x;
        save[i].insert(x);
    }
    dfs(1);
    forw(i,1,n) cout<<ans[i]<<" ";
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
