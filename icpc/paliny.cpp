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
const ll mod=1e9+9;
const ll maxN=5e4+5;
const ll base=31;
string s;
ll save1[maxN],power[maxN],n,save2[maxN];
void init()
{
    power[0]=1;
    save1[0]=save2[n+1]=0;
    forw(i,1,n)
    {
        save1[i]=((save1[i-1]*base)%mod+s[i]-'a'+1)%mod;
        power[i]=(power[i-1]*base)%mod;
    }
    forb(i,n,1)
    {
        save2[i]=((save2[i+1]*base)%mod+s[i]-'a'+1)%mod;
    }
}
ll get_hash(ll pos, ll length, int x)
{
    if (x==1) return (save1[pos]-(save1[pos-length]*power[length])%mod+mod)%mod;
    return (save2[pos]-(save2[pos+length]*power[length])%mod+mod)%mod;
}
bool check(int x)
{
    forw(i,1,n-x+1)
    {
        int length=x/2;
        ll le=get_hash(i+length-1,length,1);
        ll ri=get_hash(i+x-length,length,2);
        if (le==ri) {
            //cout<<i<<" "<<x<<endl;
            return true;
        }
    }
    return false;
}
void solve()
{
    cin>>n>>s;
    s=' '+s;
    init();
    int l=1;
    int r=n;
    int ans=1;
    while (l<r)
    {
        int mid=(l+r)/2;
        if (mid%2) mid++;
        if (check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    l=1;
    r=n;
    while (l<r)
    {
        int mid=(l+r)/2;
        if (mid%2==0) mid++;
        if (check(mid))
        {
            ans=max(ans,mid);
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
