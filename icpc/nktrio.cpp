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
const ll maxN=1500+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,0};
const ll base=31;
int n;
vector <int> check[maxN];
bool ok=false,a[maxN][maxN],color[maxN];
void dfs(int u, int father)
{
    color[u]=1;
    for(int v:check[u])
    {
        if (ok) return;
        if (!color[v]) dfs(v,u);
        else
            if (color[v]==1 && a[v][father])
            {
                ok=true;
                cout<<father<<" "<<u<<" "<<v<<endl;
                return;
            }
    }
    if (ok) return;
}
void solve()
{
    cin>>n;
    forw(i,1,n)
        forw(j,1,n)
        {
            cin>>a[i][j];
            if (a[i][j])
                check[i].pb(j);
        }
    forw(i,1,n)
    if (!color[i])
        dfs(i,i);
    if (!ok) cout<<"-1 -1 -1"<<endl;
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
