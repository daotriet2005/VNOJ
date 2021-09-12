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
const ll maxN=1e5+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
const ll base=31;
int father[maxN][18],d[maxN],G[maxN],H[maxN],n,m,u,v;
bool cost[maxN];
vector <int> check[maxN];
char c;
void dfs(int u, int up, int depth, int sumG, int sumH) // starting node - u's father - depth - sum of G - sum of H
{
    d[u]=depth;
    father[u][0]=up;
    sumG+=(cost[u]==1);
    sumH+=(cost[u]==0);
    G[u]=sumG;
    H[u]=sumH;
    forw(i,1,17)
        father[u][i]=father[father[u][i-1]][i-1];
    for(int v:check[u])
    if (v!=up)
        dfs(v,u,depth+1,sumG,sumH);
    return;
}
int jump(int node, int k)
{
    forb(i,17,0)
    if (k & (1<<i))
        node=father[node][i];
    return node;
}
int LCA(int a, int b)
{
    if (d[a]>d[b]) swap(a,b);
    b=jump(b,d[b]-d[a]);
    if (a==b) return a;
    forb(i,17,0)
    {
        int new_a=father[a][i];
        int new_b=father[b][i];
        if (new_a!=new_b)
        {
            a=new_a;
            b=new_b;
        }
    }
    return father[a][0];
}
void solve()
{
    cin>>n>>m;
    forw(i,1,n)
    {
        cin>>c;
        if (c=='G') cost[i]=1;
    }
    forw(i,1,n-1)
    {
        cin>>u>>v;
        check[u].pb(v);
        check[v].pb(u);
    }
    dfs(1,0,1,0,0);
    forw(i,1,m)
    {
        cin>>u>>v>>c;
        int node=LCA(u,v),res=0;
        node=father[node][0];
        if (c=='G')
            res=G[u]+G[v]-2*G[node];
        else
            res=H[u]+H[v]-2*H[node];
        if (res>0) cout<<1;
        else cout<<0;
    }
    return;
}
int main()
{
    fast;
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    //freopen("milkvisits.in","r",stdin);
    //freopen("milkvisits.out","w",stdout);
    ll t=1; //cin>>t;
    while (t--) solve();
    return 0;
}
