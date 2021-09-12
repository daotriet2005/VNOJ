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
const ll mod=5000000;
const int base=31;
const ll maxN=1e6+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
const int maxd=10000;
const int limit=1e5+1;
struct super
{
    ll b,c;
};
super save[3005];
ll b[3005][3005],c[3005][3005],a[3005],sum,n;
bool cmp(super a, super b)
{
    if (a.b-a.c<b.b-b.c) return true;
    return false;
}
void mini(ll &a, ll b)
{
    a=min(a,b);
    return;
}
void solve()
{
    cin>>n;
    forw(i,1,n)
    {
        cin>>a[i]>>save[i].b>>save[i].c;
        save[i].b-=a[i];
        save[i].c-=a[i];
        sum+=a[i];
    }
    sort(save+1,save+1+n,cmp);
    forw(i,0,n+1)
        forw(j,1,n+1)
            b[i][j]=c[i][j]=oo;
    forw(i,1,n)
        forw(j,1,n)
            b[i][j]=min(b[i-1][j],b[i-1][j-1]+save[i].b-j+1);
    forb(i,n,1)
        forw(j,1,n)
            c[i][j]=min(c[i+1][j],c[i+1][j-1]+save[i].c-j+1);
    ll ans=oo;
    forw(i,0,n)
    {
        ll res_b=oo,res_c=oo;
        forw(j,0,n)
        {
            mini(res_b,b[i][j]);
            mini(res_c,c[i+1][j]);
        }
        mini(ans,min(res_b+res_c,min(res_b,res_c)));
    }
    cout<<ans+sum<<endl;

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
