#include <bits/stdc++.h>
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
const ll MOD=1e9+7;
const ll maxN=1e6+5;
const ll base=31;
ll save[maxN],n,power[maxN],m;
void init()
{
    power[0]=1;
    forw(i,1,n)
        power[i]=power[i-1]*base;
}
ll get_hash(ll pos, ll length)
{
    //cout<<save[pos]<<" "<<save[pos-length]<<" "<<power[length]<<endl;
    return save[pos]-save[pos-length]*power[length];
}
void solve()
{
    string s,t; cin>>s>>t;
    n=s.length();
    m=t.length();
    s=' '+s;
    t=' '+t;
    init();
    ll res=0;
    forw(i,1,m)
        res=res*base+t[i]-'a'+1;
    //cout<<res<<endl;
    forw(i,1,n)
    {
        save[i]=save[i-1]*base+s[i]-'a'+1;
        ll p=get_hash(i,m);
        if (i-m>=0 && res==p)
            cout<<i-m+1<<" ";
    }
}
int main()
{
    fast;
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    int t=1; //cin>>t;
    while (t--)
        solve();
    return 0;
}
