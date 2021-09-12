#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
//typedef pair<ll,ll> data;
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
ll n,ans,a[10][10005],dp[10005][10][10];
bool check(int x1,int x2,int y1, int y2)
{
    if (x1==y1 || x1==y2 || x2==y1 || x2==y2) return false;
    if (y2==y1-1) return false;
    if (x2==x1-1) return false;
    return true;
}
int main()
{
    fast;
    ans=-oo;
    cin>>n;
    fore(i,1,4)
        fore(j,1,n)
        {
            cin>>a[i][j];
            ans=max(ans,a[i][j]);
        }
    fore(j,1,n)
        fore(x1,1,4)
            fore(x2,1,x1)
            {
                dp[j][x1][x2]=dp[j-1][x1][x2];
                fore(y1,1,4)
                    fore(y2,1,y1)
                    if (check(x1,x2,y1,y2))
                    {
                        dp[j][x1][x2]=max(dp[j][x1][x2],max(dp[j-1][y1][y2],dp[j-1][y1][y2]+a[x1][j]+(x1!=x2)*a[x2][j]));
                        if (dp[j][x1][x2]==dp[j-1][y1][y2]+a[x1][j]+(x1!=x2)*a[x2][j])
                        ans=max(ans,dp[j][x1][x2]);
                    }
            }
    cout<<ans;
    return 0;
}
