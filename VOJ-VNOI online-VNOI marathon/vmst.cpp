#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> data;
typedef pair<ll, pair<ll, ll> > pii;
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
const ll mod=1e9;
const int base=31;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
// custom
const ll maxN=1505;
/////
data save[maxN];
vector <data> take,ans;
int father[maxN],n,m,dem;
bool ok[maxN];
int findFather(int u)
{
    if (u==father[u]) return u;
    return findFather(father[u]);
}
void solve()
{
    cin>>n>>m;
    forw(i,1,n) father[i]=i;
    forw(i,1,m)
    {
        cin>>save[i].fi>>save[i].se;
        int father_u=findFather(save[i].fi);
        int father_v=findFather(save[i].se);
        if (father_u!=father_v)
        {
            take.pb(save[i]);
            father[father_u]=father_v;
        }
    }
    cout<<3<<endl;
    for(auto res:take)
        cout<<res.fi<<" "<<res.se<<endl;
    forw(j,0,take.size()-1)
    {
        forw(i,1,n) father[i]=i;
        ans.clear();
        forw(i,1,m)
        {
            int u=save[i].fi;
            int v=save[i].se;
            int father_u=findFather(father[u]);
            int father_v=findFather(father[v]);
            if ((u!=take[j].fi || v!=take[j].se) && father_u!=father_v)
            {
                father[father_u]=father_v;
                ans.pb(save[i]);
            }
        }
        if (ans.size()==n-1)
        {
            dem++;
            for(auto res:ans)
                cout<<res.fi<<" "<<res.se<<endl;
        }
        if (dem==2) return;
    }
    cout<<1<<endl;
    for(auto res:take)
        cout<<res.fi<<" "<<res.se<<endl;
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
