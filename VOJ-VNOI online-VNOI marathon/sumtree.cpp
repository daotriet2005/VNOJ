#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> data;
typedef pair<int, pair<int, int> > pii;
#define forw(i,a,b) for (int i=a;i<=b;i++)
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
const ll maxN=1e6+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,0};
const ll base=31;
map<ll,int> save;
int n,s,a[maxN];
ll ans;
vector<int> check[maxN];
void dfs(int u, ll sum)
{
    sum+=a[u];
    ans+=save[sum-s];
    save[sum]++;
    for(int v:check[u])
        dfs(v,sum);
    save[sum]--;
}
void solve()
{
    cin>>n>>s;
    forw(i,1,n)
    {
        int u;
        cin>>u>>a[i];
        check[u].pb(i);
    }
    save[0]++;
    dfs(1,0);
    cout<<ans<<endl;
}
int main()
{
    fast;
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    ll t=1; //cin>>t;
    while (t--) solve();
}
