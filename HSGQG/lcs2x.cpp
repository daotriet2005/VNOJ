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
const ll maxN=3e4+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
const ll base=31;
const int maxd=10000;
int dp[1505],n,m,a[1505],b[1505];
void solve()
{
    cin>>n>>m;
    forw(i,1,n) cin>>a[i];
    forw(i,1,m) {
        cin>>b[i];
        dp[i]=0;
    }
    int ans=0;
    forw(i,1,n)
    {
        int res=0;
        forw(j,1,m)
        {
            if (b[j]==a[i])
            {
                int tmp=dp[j];
                dp[j]=max(dp[j],res+1);
                ans=max(ans,dp[j]);
                if (b[j]==0)
                    res=max(res,tmp);
                continue;
            }
            if (b[j]*2<=a[i])
                res=max(res,dp[j]);
        }
    }
    cout<<ans<<endl;
}
int main()
{
    fast;
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    ll t=1; cin>>t;
    while (t--) solve();
    return 0;
}
