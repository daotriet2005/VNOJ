#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> data;
typedef pair<ll, string> super;
#define fore(i,a,b) for (ll i=a;i<=b;++i)
#define forw(i,a,b) for (ll i=a;i>=b;i--)
#define fast {ios::sync_with_stdio(false); cin.tie(0); }
#define fi first
#define se second
#define pu push
#define pb push_back
#define fr front
const ll oo=1e18;
const ll MOD=1e9+7;
ll n,m,a[1005][1005],dp[1005][1005][5];
int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
    cin>>n>>m;
    fore(i,1,n)
        fore(j,1,m)
            cin>>a[i][j];
    fore(i,1,n)
        dp[i][1][2]=a[i][1];
    fore(j,1,m)
        dp[1][j][1]=a[1][j];
    //dp[1][1][1]=dp[1][1][2]=a[1][1];
    fore(i,1,n)
        fore(j,1,m)
        {
            dp[i+1][j][1]=min(dp[i][j][1],dp[i][j][2]+a[i+1][j]);
            dp[i][j+1][2]=min(dp[i][j][2],dp[i][j][1]+a[i][j+1]);
        }
    cout<<min(dp[n][m][1],dp[n][m][2])<<endl;
    }
    return 0;
}
