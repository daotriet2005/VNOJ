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
vector <data> process[3];
int vis[maxN][maxN],n,m,father[maxN*maxN],dp[maxN][maxN];
data save[3];
bool a[maxN][maxN];
bool valid(int x, int y)
{
    if (1<=x && x<=n)
        if (1<=y && y<=m) return 1;
    return 0;
}
void bfs(int x, int y, int mark)
{
    queue<data> p1;
    vis[x][y]=mark;
    p1.pu({x,y});
    process[0].pb({x,y});
    while (!p1.empty())
    {
        x=p1.fr().fi;
        y=p1.fr().se;
        p1.pop();
        forw(i,0,3)
        {
            int xx=x+tx[i];
            int yy=y+ty[i];
            if (valid(xx,yy) && a[xx][yy] && !vis[xx][yy])
            {
                vis[xx][yy]=mark;
                p1.pu({xx,yy});
                process[0].pb({xx,yy});
            }
        }
    }
}
int findFather(int u)
{
    if (u==father[u]) return u;
    return father[u]=findFather(father[u]);
}
bool disjoint(int u, int v)
{
    int father_u=findFather(u);
    int father_v=findFather(v);
    if (father_u!=father_v)
    {
        father[father_v]=father_u;
        return true;
    }
    return false;
}
int bfs2()
{
    int ans=0;
    int res=1;
    for(;;)
    {
        res=res^1;
        /////////////////// disjoint
        for(auto tmp:process[res])
        {
            int x=tmp.fi;
            int y=tmp.se;
            forw(i,0,3)
            {
                int xx=x+tx[i];
                int yy=y+ty[i];
                if (valid(xx,yy))
                    if (vis[xx][yy])
                        disjoint(vis[x][y],vis[xx][yy]);
            }
        }
        int u=findFather(vis[save[1].fi][save[1].se]);
        int v=findFather(vis[save[2].fi][save[2].se]);
        if (u==v)
            return ans;
        /////////////////////// loang
        for(auto tmp:process[res])
        {
            int x=tmp.fi;
            int y=tmp.se;
            forw(i,0,3)
            {
                int xx=x+tx[i];
                int yy=y+ty[i];
                if (valid(xx,yy))
                    if (!vis[xx][yy])
                    {
                        vis[xx][yy]=vis[x][y];
                        process[res^1].pb({xx,yy});
                    }
            }
        }
        process[res].clear();
        ans++;
    }
}
void solve()
{
    cin>>n>>m;
    int tmp=0;
    forw(i,1,n)
    {
        forw(j,1,m)
        {
            char c;
            cin>>c;
            if (c!='X') a[i][j]=1;
            if (c=='L')
            {
                tmp++;
                save[tmp]={i,j};
            }
        }
    }
    int dem=0;
    forw(i,1,n)
        forw(j,1,m)
            if (!vis[i][j] && a[i][j])
                bfs(i,j,++dem);
    forw(i,1,dem) father[i]=i;
    cout<<bfs2()<<endl;
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
