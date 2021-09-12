#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> data;
typedef pair<ll, string> super;
#define fore(i,a,b) for (ll i=a;i<=b;i++)
#define forw(i,a,b) for (ll i=a;i>=b;i--)
#define fast {ios::sync_with_stdio(false); cin.tie(0); }
#define fi first
#define se second
#define pu push
#define puf push_front
#define pub push_back
#define pof pop_front
#define pob pop_back
#define fr front
const ll oo=1e18;
const ll MOD=1e9+7;
ll dp[1005][1005],x,n,m,ans;
ll l[1005],r[1005];
void solve()
{
    cin>>n>>m;
    fore(i,1,n)
    {
        fore(j,1,m)
        {
            cin>>x;
            if (!x) continue;
            dp[i][j]=dp[i-1][j]+1;
        }
    }
    fore(i,1,n)
    {
        deque<int> p;
        fore(j,1,m)
        {
            while (!p.empty() && dp[i][p.back()]>=dp[i][j]) p.pob();
            if (p.empty()) l[j]=1;
            else l[j]=p.back()+1;
            p.pub(j);
        }
        p.clear();
        forw(j,m,1)
        {
            while (!p.empty() && dp[i][j]<=dp[i][p.back()])p.pob();
            if (p.empty()) r[j]=m;
            else r[j]=p.back()-1;
            p.pub(j);
        }
        fore(j,1,m)
            ans=max(ans,dp[i][j]*(r[j]-l[j]+1));
    }
    cout<<ans;
}
int main()
{
    fast;
    solve();
    return 0;
}
