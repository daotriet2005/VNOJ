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
const ll maxN=100+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,0};
const ll base=31;
bool vis[maxN][maxN];
int a[maxN][maxN],dp[maxN][maxN],n;
bool valid(int x, int y, int low)
{
    if (1<=x && x<=n)
        if (1<=y && y<=n)
            if (!vis[x][y] && a[x][y]>=low)
                return true;
    return false;
}
int dijk(int low)
{
    priority_queue<pii, vector <pii> , greater<pii> > p;
    forw(i,1,n)
        forw(j,1,n)
        {
            vis[i][j]=false;
            dp[i][j]=1e9;
        }
    dp[1][1]=a[1][1];
    p.pu({a[1][1],{1,1,}});
    while (!p.empty())
    {
        int val=p.top().fi;
        int x=p.top().se.fi;
        int y=p.top().se.se;
        p.pop();
        if (vis[x][y]) continue;
        vis[x][y]=true;
        forw(i,0,3)
        {
            int xx=x+tx[i];
            int yy=y+ty[i];
            if (!valid(xx,yy,low)) continue;
            if (max(dp[x][y],a[xx][yy])<dp[xx][yy])
                {
                    dp[xx][yy]=max(dp[x][y],a[xx][yy]);
                    p.pu({dp[xx][yy],{xx,yy}});
                }
        }
    }
    return dp[n][n];
}
void solve()
{
    priority_queue<int, vector<int> , greater<int> > p;
    cin>>n;
    forw(i,1,n)
        forw(j,1,n)
        {
            cin>>a[i][j];
            p.pu(a[i][j]);
        }
    int ans=INT_MAX;
    int save=1e9;
    while (!p.empty())
    {
        int low=p.top();
        p.pop();
        if (low>a[1][1] || low>a[n][n] || low==save) continue;
        save=low;
        int res=dijk(low);
        //cout<<res<<" "<<low<<endl;
        ans=min(ans,res-low);
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
