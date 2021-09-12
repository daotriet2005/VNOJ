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
const ll maxN=5e4+5;
const ll base=31;
int save[maxN],n,k;
ll power[maxN];
string s;
void init()
{
    power[0]=1;
    forw(i,1,n)
    {
        power[i]=(power[i-1]*base)%mod;
        save[i]=(save[i-1]*base+s[i]-'a'+1)%mod;
    }
}
ll get_hash(ll pos, ll length)
{
    return (save[pos]-save[pos-length]*power[length]+mod*mod)%mod;
}
bool check(int x)
{
    map<int, int> dem;
    forw(i,1,n-x+1)
    {
        ll p=get_hash(i+x-1,x);
        dem[p]++;
        if (dem[p]>=k) return true;
    }
    return false;
}
void solve()
{
    cin>>n>>k;
    cin>>s;
    s=' '+s;
    init();
    int l=1;
    int r=n-k+1;
    int ans=0;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
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

