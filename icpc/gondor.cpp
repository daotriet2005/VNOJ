// idea: dp[i] = luong nuoc nho nhat de di tu i -> n
// in case you need:
// https://acceptedcode.blogspot.com/2016/08/nk05dsrt-sa-mac.html
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
const ll oo=1e9;
const ll mod=1e9;
const int base=31;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,0};
// custom
const ll maxN=100+5;
////////
double dp[maxN];
ll n,s[maxN];
pair<ll, ll> a[maxN];
vector <int> check[maxN];
bool vis[maxN];
double calc(int u, int v)
{
    double x=abs(a[u].fi-a[v].fi);
    double y=abs(a[u].se-a[v].se);
    return sqrt(x*x+y*y);
}
void dijk()
{
    forw(i,1,n) dp[i]=oo;
    priority_queue<data, vector <data> , greater<data> > p;
    p.pu({0,1});
    dp[1]=0;
    while (!p.empty())
    {
        ll u=p.top().se;
        double val=p.top().fi;
        p.pop();
        if (val>dp[u]) continue;
        int dem=0;
        vis[u]=true;
        for(auto v:check[u])
        {
            double res=calc(u,v);
            if (dem>=s[u]) break;
            if (vis[v]) continue;
            if (val+res<dp[v])
            {
                dp[v]=val+res;
                p.pu({dp[v],v});
            }
            dem++;
        }
    }
    forw(i,1,n)
    {
        printf("%.3f \n",dp[i]);
    }
}
void solve()
{
    cin>>n;
    forw(i,1,n)
    {
        int m,v;
        cin>>a[i].fi>>a[i].se>>s[i];
        forw(j,1,n-1)
        {
            cin>>v;
            check[i].pb(v);
        }
    }
    dijk();
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
