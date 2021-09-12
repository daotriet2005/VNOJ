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
const ll maxN=500+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,0};
const ll base=31;
struct coor
{
    int x,y;
    coor(int x, int y)
    {
        this->x=x;
        this->y=y;
    }
};
queue<coor> p;
bool vis[maxN][maxN];
int min1[maxN][maxN],n,m;
coor s={0,0};
coor t={0,0};
bool bfs(int res)
{
    forw(i,1,n)
        forw(j,1,m) vis[i][j]=false;
    queue<coor> p;
    p.pu({s.x,s.y});
    vis[s.x][s.y]=true;
    if (min1[s.x][s.y]<res) return false;
    while (!p.empty())
    {
        int x=p.fr().x;
        int y=p.fr().y;
        p.pop();
        if (x==t.x && y==t.y) return true;
        forw(i,0,3)
        {
            int xx=x+tx[i];
            int yy=y+ty[i];
            if (1<=xx && xx<=n)
                if (1<=yy && yy<=m)
                    if (!vis[xx][yy] && min1[xx][yy]>=res)
                    {
                        vis[xx][yy]=true;
                        p.pu({xx,yy});
                    }
        }
    }
    return false;
}
void get_min_dist()
{
    while (!p.empty())
    {
        int x=p.fr().x;
        int y=p.fr().y;
        p.pop();
        forw(i,0,3)
        {
            int xx=x+tx[i];
            int yy=y+ty[i];
            if (1<=xx && xx<=n)
            if (1<=yy && yy<=m)
            if (min1[x][y]+1<min1[xx][yy])
            {
                min1[xx][yy]=min1[x][y]+1;
                p.pu({xx,yy});
            }
        }
    }
}
void solve()
{

    cin>>n>>m;
    forw(i,1,n)
        forw(j,1,m)
        {
            char c;
            cin>>c;
            if (c=='V')
                s={i,j};
            if (c=='J')
                t={i,j};
            if (c=='+')
            {
                min1[i][j]=0;
                p.pu({i,j});
            }
            else min1[i][j]=1e9;
        }
    get_min_dist();
    int l=0;
    int r=1000;
    int ans=0;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (bfs(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
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