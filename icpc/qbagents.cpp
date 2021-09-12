#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> data;
typedef pair<int, pair<int, int> > pii;
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
const ll maxN=250+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,0};
const ll base=31;
int n,m,s,t,dp[maxN][maxN][3];
bool vis[maxN][maxN][3],got[maxN][maxN];
vector <int> check[maxN];
void solve()
{
    cin>>n>>m>>s>>t;
    forw(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        if (got[u][v]) continue;
        got[u][v]=true;
        check[u].pb(v);
    }
    queue<pii> p;
    int tmp1=min(s,t);
    int tmp2=max(s,t);
    s=tmp1;
    t=tmp2;
    p.pu({0,{s,t}});
    vis[s][t][0]=true;
    while (!p.empty())
    {
        int res=p.fr().fi;
        int u=p.fr().se.fi;
        int v=p.fr().se.se;
        p.pop();
        if (res==0)
        {
            for(int x:check[v])
            if (!vis[u][x][res^1])
            {
                vis[u][x][res^1]=true;
                dp[u][x][res^1]=dp[u][v][res]+1;
                p.pu({res^1,{u,x}});
            }
        }
        else
        {
            for(int x:check[u])
            if (!vis[x][v][res^1])
            {
                vis[x][v][res^1]=true;
                dp[x][v][res^1]=dp[u][v][res]+1;
                p.pu({res^1,{x,v}});
            }
        }
    }
    int ans=1e9;
    forw(i,1,n)
    if (vis[i][i][0] && dp[i][i][0]<ans)
        ans=dp[i][i][0];
    if (ans==1e9) cout<<-1;
    else cout<<ans/2<<endl;
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
