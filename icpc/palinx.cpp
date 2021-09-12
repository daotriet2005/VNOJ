#include <iostream>
#include <map>
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
const ll mod=1e9+9;
const ll maxN=1e6+5;
const ll base=31;
map<ll,ll> all_le,all_ri,le,ri;
ll power[maxN],dp_ri[maxN],dp_le[maxN];
void init()
{
    power[0]=1;
    forw(i,1,maxN)
        power[i]=(power[i-1]*base)%mod;
}
void solve()
{
    ll n,m; string s;
    ll ans=0;
    cin>>m;
    init();
    forw(pos,1,m)
    {
        cin>>n>>s;
        s=' '+s;
        dp_le[0]=dp_ri[n+1]=0;
        forw(i,1,n)
            dp_le[i]=(dp_le[i-1]*base+s[i]-'a'+1)%mod;
        forb(i,n,1)
            dp_ri[i]=(dp_ri[i+1]*base+s[i]-'a'+1)%mod;
        all_le[dp_le[n]]++;
        all_ri[dp_ri[1]]++;
        forw(i,2,n)
        {
            ll length=(n-i+1)/2;
            ll tmp1=(dp_le[i+length-1]-dp_le[i-1]*power[length]+mod*mod)%mod;
            ll tmp2=dp_ri[n-length+1];
            if (tmp1==tmp2)
            {
                ll res=dp_le[i-1];
                le[res]++;
            }
        }
        forb(i,n-1,1)
        {
            ll length=i/2;
            ll tmp1=dp_le[length];
            ll tmp2=(dp_ri[i-length+1]-dp_ri[i+1]*power[length]+mod*mod)%mod;
            if (tmp1==tmp2)
            {
                ll res=dp_ri[i+1];
                //cout<<pos<<" "<<i<<" "<<res<<endl;
                ri[res]++;
            }
        }
    }
    for(auto res:all_le)
    {
        ll val=res.fi;
        ll num=res.se;
        //cout<<val<<" "<<num<<" "<<ri[val]<<endl;
        ans+=num*ri[val];
        ans+=num*all_ri[val];
        //cout<<val<<" "<<num<<" "<<all_ri[val]<<endl;
    }
    for(auto res:all_ri)
    {
        ll val=res.fi;
        ll num=res.se;
        ans+=le[val]*num;
    }
    cout<<ans<<endl;
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
