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
ll dp[maxN][3],power[maxN];
void init()
{
    power[0]=1;
    forw(i,1,1e6)
        power[i]=(power[i-1]*base)%mod;
}
ll get_hash(int u, int v, int x)
{
    return (dp[v][x]-dp[u-1][x]*power[v-u+1]+mod*mod)%mod;
}
void solve()
{
    int n,m,k; string s1,s2;
    init();
    cin>>n>>m;
    cin>>s1>>s2;
    s1=' '+s1;
    s2=' '+s2;
    dp[0][1]=dp[0][2]=0;
    forw(i,1,n)
        dp[i][1]=(dp[i-1][1]*base+s1[i]-'a'+1)%mod;
    forw(i,1,m)
        dp[i][2]=(dp[i-1][2]*base+s2[i]-'a'+1)%mod;
    cin>>k;
    forw(i,1,k)
    {
        int u1,v1,u2,v2;
        cin>>u1>>v1>>u2>>v2;
        ll length1=v1-u1+1;
        ll length2=v2-u2+1;
        ll length=min(length1,length2)-1;
        ll l=0;
        ll r=length;
        ll ans=length+1;
        while (l<=r)
        {
            ll mid=(l+r)/2;
            ll p1=get_hash(u1,u1+mid,1);
            ll p2=get_hash(u2,u2+mid,2);
            if (p1!=p2)
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        if (ans!=length+1)
            if (s1[u1+ans]<s2[u2+ans]) cout<<"<";
            else cout<<">";
        else
            if (length1==length2) cout<<"=";
            else
                if (length1>length2) cout<<">";
                else cout<<"<";
        //if (p1<p2) cout<<"<";
        //if (p1==p2) cout<<"=";
        //if (p1>p2) cout<<">";
       // cout<<p1<<" "<<p2<<endl;
    }
    return;
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
