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
const ll maxN=2e5+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
const ll base=31;
ll n,k,a[305],dp[305][305][305];
void solve()
{
    cin>>n>>k;
    forw(i,1,n)
        cin>>a[i];
    forw(length,1,n-1)
    {
        forw(l,1,n-length)
        {
            int r=l+length;
            forw(i,0,k)
            {
                if (2*k<n)
                    dp[l][r][i]=max(dp[l][r][i],max(dp[l+1][r][i],dp[l][r-1][i]));
                dp[l][r][i+1]=max(dp[l+1][r-1][i]+abs(a[l]-a[r]),max(dp[l][r-2][i]+abs(a[r]-a[r-1]),dp[l+2][r][i]+abs(a[l]-a[l+1])));
            }
        }
    }
    cout<<dp[1][n][k]<<endl;
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
