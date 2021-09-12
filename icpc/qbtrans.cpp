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
pii save[9005];
int n,m;
bool down(pii res,double x)
{
    int u=res.se.fi;
    int v=res.se.se;
    double val=res.fi-x;
    bool tmp=0;
    if (dp[u]+val<dp[v])
    {
        tmp=1;
        dp[v]=dp[u]+val;
    }
    return tmp;
}
bool ok(double x)
{
    forw(i,1,n) dp[i]=0;
    forw(i,1,n)
    {
        bool stop=false;
        forw(j,1,m)
            if (down(save[j],x))
                stop=false;
        if (stop) break;
    }
    forw(j,1,m)
    if (down(save[j],x)) return true;
    return false;
}
void solve()
{
    cin>>n>>m;
    forw(i,1,m)
    {
        cin>>save[i].se.fi>>save[i].se.se>>save[i].fi;
    }
    double l=0;
    double r=1e9;
    double ans=0;
    while (r-l>0.0001)
    {
        double mid=(l+r)/2;
        if (ok(mid))
        {
            r=mid;
            ans=mid;
        }
        else l=mid;
    }
    if (ans==0 || ans>1e8) cout<<-1<<endl;
    else printf("%.2f",ans);
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
