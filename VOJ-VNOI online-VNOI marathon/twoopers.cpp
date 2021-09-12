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
const ll mod=1e9+7;
const ll maxN=1e6+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
const ll base=31;
ll power[maxN],dp[maxN][3];
void init()
{
    power[0]=1;
    forw(i,1,1e5)
        power[i]=(power[i-1]*base)%mod;
}
ll get_hash(int i, int j, int x)
{
    return (dp[j][x]-dp[i-1][x]*power[j-i+1]+mod*mod)%mod;
}
void solve()
{
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    s1=' '+s1+s1;
    s2=' '+s2+s2;
    ll out=0;
    init();
    forw(i,1,2*n)
    {
        dp[i][1]=(dp[i-1][1]*base+s1[i]-'a'+1)%mod;
        dp[i][2]=(dp[i-1][2]*base+s2[i]-'a'+1)%mod;
    }
    forw(i,1,n)
    {
        int u1=i;
        int v1=i+n-1;
        int u2=1;
        int v2=n;
        //cout<<u1<<" "<<v1<<" "<<u2<<" "<<v2<<endl;
        //forw
        if (get_hash(u1,v1,1)==get_hash(u2,v2,2))
        {
            //cout<<"yes"<<endl;
            out+=n;
            continue;
        }
        if ( get_hash(u1+1,v1,1)==get_hash(u2+1,v2,2) || get_hash(u1,v1-1,1)==get_hash(u2,v2-1,2))
        {
            //cout<<"br"<<endl;
            out++;
            continue;
        }
        int l=0;
        int r=n-1;
        int ans=0;
        while (l<=r)
        {
            int mid=(l+r)/2;
            ll p1=get_hash(u1,u1+mid,1);
            ll p2=get_hash(u2,u2+mid,2);
            //cout<<mid<<" "<<p1<<" "<<p2<<endl;
            if (p1==p2)
            {
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        //cout<<i<<" "<<ans<<endl;
        ll pre1=get_hash(u1,u1+ans,1);
        ll pre2=get_hash(u2,u2+ans,2);
        ll suf1=get_hash(u1+ans+2,v1,1);
        ll suf2=get_hash(u2+ans+2,v2,2);
        if (pre1==pre2 && suf1==suf2)
            out++;
    }
    cout<<out<<endl;
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
