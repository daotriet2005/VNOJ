//https://oj.vnoi.info/problem/mcards
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
const ll mod=1e8;
const ll maxN=2e5+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
const ll base=31;
ll n,c,color[5],a[maxN],b[maxN];
void solve()
{
    cin>>c>>n;
    forw(i,1,n*c) cin>>b[i]>>a[i];
    ll res=1;
    forw(i,1,c) {
        res*=i;
        color[i]=i;
    }
    ll ans=oo;
    forw(i,1,res)
    {
        vector <ll> dp;
        forw(i,1,n*c)
        {
            ll val=color[b[i]]*100000+a[i];
            //cout<<val<<endl;
            ll pos=lower_bound(all(dp),val)-dp.begin();
            if (pos==dp.size()) dp.pb(val);
            else dp[pos]=val;
        }
        //cout<<dp.size()<<endl;
        ll p=n*c-dp.size();
        ans=min(ans,p);
        next_permutation(color+1,color+1+c);
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
