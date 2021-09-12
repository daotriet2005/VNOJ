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
const ll oo=1e14;
const ll mod=1000001;
const ll maxN=30000+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
const ll base=31;
ll nCk[105][105],res[105];
void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;
    cout<<(nCk[n][k]*nCk[m][k]*res[k])%mod<<endl;
}
int main()
{
    fast;
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    forw(i,0,100)
        nCk[i][i]=nCk[i][0]=1;
    res[0]=1;
    forw(i,1,100) res[i]=(res[i-1]*i)%mod;
    forw(i,1,50)
        forw(j,1,100)
        if (i!=j) nCk[i][j]=(nCk[i-1][j-1]+nCk[i-1][j])%mod;
    ll t=1; cin>>t;
    while (t--) solve();
    return 0;
}
