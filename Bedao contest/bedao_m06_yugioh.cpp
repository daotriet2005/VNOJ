#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> data;
typedef pair<int, pair<int, int> > pii;
#define forw(i,a,b) for (int i=a;i<=b;i++)
#define forb(i,a,b) for (int i=a;i>=b;i--)
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
ll n,x,num,pre[maxN];
bool notprime[maxN],isprime[maxN];
void sieve()
{
    for(ll i=2;i<=x;i++)
    if (!notprime[i])
    {
        isprime[i]=true;
        for(ll j=i*i;j<=x;j+=i)
            notprime[j]=true;
    }
}
void solve()
{
    cin>>n>>x;
    sieve();
    forw(i,1,n)
    {
        cin>>num;
        if (0<=num && num<=x && isprime[num]) pre[i]=pre[i-1]+1;
        else pre[i]=pre[i-1];
    }
    num=pre[n];
    ll ans=num;
    forw(i,num,n)
    {
        //cout<<i<<" "<<num-(pre[i]-pre[i-num])<<endl;
        ans=min(ans,num-(pre[i]-pre[i-num]));
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
