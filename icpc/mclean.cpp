#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> data;
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
const ll maxN=4e6+5;
typedef pair<int, vi > super;
/////
    // a=0: vat can
    // a=1: sach
    // a=2: ban
    // a=3: robot
bool vis[25][25];
vector <data> save;
ll n,m,a[25][25],dp[25][25],bit[5000][15],dis[15][15];
void mini(ll &a, ll b)
{
    a=min(a,b);
}
bool ok(int x, int y)
{
    if (0<x && x<=n)
        if (0<y && y<=m)
            if (!vis[x][y] && a[x][y]) return true;
    return false;
}
void dijk(int x, int y)
{
    memset(vis, false, sizeof vis);
    queue<data> p;
    vis[x][y]=true;
    dp[x][y]=0;
    p.pu({x,y});
    while (!p.empty())
    {
        x=p.fr().fi;
        y=p.fr().se;
        p.pop();
        forw(i,0,3)
        {
            int xx=x+tx[i];
            int yy=y+ty[i];
            if (ok(xx,yy))
            {
                dp[xx][yy]=dp[x][y]+1;
                vis[xx][yy]=true;
                p.pu({xx,yy});
            }
        }
    }
}
void solve()
{
    save.clear();
    save.pb({0,0});
    forw(i,1,n)
    forw(j,1,m)
    {
        char x;
        cin>>x;
        if (x=='.') a[i][j]=1;
        if (x=='*') a[i][j]=2;
        if (x=='x') a[i][j]=0;
        if (x=='o') a[i][j]=3;
        if (a[i][j]==2) save.pb({i,j});
        if (a[i][j]==3) save[0]={i,j};
    }
    forw(i,0,save.size()-1)
    {
        dijk(save[i].fi,save[i].se);
        forw(j,0,save.size()-1)
            dis[i][j]=dp[save[j].fi][save[j].se];
        if (i==0)
        {
            bool check=true;
            forw(i,1,save.size()-1)
                if (!vis[save[i].fi][save[i].se]) check =false;
            if (!check)
            {
                cout<<-1<<endl;
                return;
            }
        }
    }
    forw(i,0,(1<<save.size())-1)
        forw(j,0,save.size()-1)
            bit[i][j]=oo;
    bit[1][0]=0;
    forw(mask,1,(1<<save.size())-1)
    {
        forw(last,0,save.size()-1)
        if (mask & (1<<last))
        {
            forw(i,0,save.size()-1)
            if (!(mask & (1<<i)))
                mini(bit[ mask|(1<<i) ][i],bit[mask][last]+dis[last][i]);
        }
    }
    ll ans=oo;
    forw(i,1,save.size()-1)
        mini(ans,bit[(1<<save.size())-1][i]);
    cout<<ans<<endl;
}
int main()
{
    fast;
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    ll t=1; //cin>>t;
    while (cin>>m>>n && n!=0 && m!=0) solve();
    return 0;
}
