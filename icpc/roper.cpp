#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pi;
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
const ll mod=1e9+7;
const int base=31;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
// custom
const ll maxN=1e5+5;
/////
int n,m,u,v,father[maxN],p[maxN];
void solve()
{
    cin>>n>>m;
    forw(i,1,n)
        cin>>p[i];
    forw(i,1,n)
    {
        int j=i;
        while (father[j]==0)
        {
            father[j]=i;
            j=p[j];
        }
    }
    forw(i,2,n)
    if (father[i]==father[1])
        father[i]=father[2];
    father[1]=father[2];
    forw(i,1,m)
    {
        cin>>u>>v;
        if (father[u]==father[v]) puts("Yes");
        else puts("No");
    }
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
