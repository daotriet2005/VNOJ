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
const ll maxN=1e5+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,0};
//const ll base=31;
string s;
ll p,pre[maxN];
double dp[maxN];
ll fexp(ll a, ll n)
{
    ll ans=1;
    while (n>0)
    {
        if (n%2) ans=(ans*a)%mod;
        a=(a*a)%mod;
        n/=2;
    }
    return ans;
}
ll getdiv(ll a, ll b)
{
    return ((a%mod)*(fexp(b,mod-2)%mod))%mod;
}
void solve()
{
    cin>>s;
    forw(i,0,s.length()-1)
        p=(p*10+(s[i]-'0'))%mod;
    int len=s.length();
    int l=1;
    int n=1e5;
    pre[0]=1;
    forw(i,1,n)
    {
        dp[i]=dp[i-1]+log10(i);
        pre[i]=(pre[i-1]*i)%mod;
    }
    bool stop=false;
    forw(r,1,n)
    {
        while (l<r && dp[r]-dp[l-1]>len) l++;
        forw(j,max(2,l-10),min(l+10,r))
        if (getdiv(pre[r],pre[j-1])==p)
        {
            cout<<j<<" "<<r<<endl;
            stop=true;
            break;
        }
        if (stop) break;
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
