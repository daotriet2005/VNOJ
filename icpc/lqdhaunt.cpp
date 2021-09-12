#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long int ll;
typedef pair<double,ll> data;
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
const ll oo=1e8;
const ll mod=1e9;
const int base=31;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,0};
// custom
const ll maxN=30+5;
////////
vector <pii> check[maxN][maxN];
bool a[maxN][maxN];
ll dp[maxN][maxN],w,h;
void reset()
{
    memset(a,false,sizeof a);
    forw(i,0,w-1)
        forw(j,0,h-1)
        {
            dp[i][j]=oo;
            check[i][j].clear();
        }
    dp[0][0]=0;
}
bool test(int x,int y)
{
    if (0<=x && x<w)
        if (0<=y && y<h)
            if (!a[x][y]) return true;
    return false;
}
bool update(int x, int y, ll val)
{
    bool ok=false;
    if (val==oo) return ok;
    for(auto res:check[x][y])
    {
        ll t=res.fi;
        ll xx=res.se.fi;
        ll yy=res.se.se;
        if (val+t<dp[xx][yy])
        {
            dp[xx][yy]=val+t;
            ok=true;
        }
    }
    return ok;
}
void bellman()
{
    forw(times,1,w*h)
    {
        bool stop=true;
        forw(i,0,w-1)
            forw(j,0,h-1)
                if (update(i,j,dp[i][j]))
                    stop=false;
        if (stop) break;
    }
    forw(i,0,w-1)
        forw(j,0,h-1)
            if (update(i,j,dp[i][j]))
            {
                cout<<"Never"<<endl;
                return;
            }
    if (dp[w-1][h-1]==oo) cout<<"Impossible"<<endl;
    else cout<<dp[w-1][h-1]<<endl;
}
void solve()
{
    //cin>>w>>h;
    ll x,y,x2,y2,m1,m2,t;
    cin>>m1;
    reset();
    forw(i,1,m1)
    {
        cin>>x>>y;
        a[x][y]=true;
    }
    cin>>m2;
    forw(i,1,m2)
    {
        cin>>x>>y>>x2>>y2>>t;
        check[x][y].pb({t,{x2,y2}});
    }
    forw(i,0,w-1)
        forw(j,0,h-1)
        if (!a[i][j] && (i!=w-1 || j!=h-1) && check[i][j].size()==0)
            forw(k,0,3)
            {
                x=i+tx[k];
                y=j+ty[k];
                if (test(x,y))
                    check[i][j].pb({1,{x,y}});
            }
    bellman();

}
int main()
{
    fast;
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    ll t=1; //cin>>t;
    while (cin>>w>>h && w!=0 && h!=0) solve();
    return 0;
}
