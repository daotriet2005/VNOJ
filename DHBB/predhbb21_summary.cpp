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
const ll mod=1e9;
const int base=31;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
// custom
const ll maxN=1005;
/////
ll a[7];
bool triangle(ll a, ll b, ll c)
{
    if (a+b>c && a+c>b && b+c>a) return true;
    return false;
}
bool heron(ll u, ll U, ll v, ll V, ll w, ll W)
{
    long double X = (w * w + u * u - V * V);
    long double Y = (v * v + w * w - U * U);
    long double Z = (u * u + v * v - W * W);
    long double T = (u * v * w);
    return (sqrt(X * Y * Z + 2 * 2 * T * T - u * u * Y * Y - v * v * X * X - w * w * Z * Z) / 12)>0;
}
bool solve()
{
    cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6];
    sort(a+1,a+7);
    if (a[1] <= 0) return false;
    do
    {
        if (triangle(a[1],a[4],a[5]) && triangle(a[2],a[5],a[6]) && triangle(a[3],a[4],a[6]) && triangle(a[1],a[2],a[3]) && heron(a[6],a[1],a[4],a[2],a[5],a[3])) return true;
    }while (next_permutation(a+1,a+7));
    return false;
}
int main()
{
    fast;
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    ll t=1; cin>>t;
    while (t--)
        if (solve()) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    return 0;
}
