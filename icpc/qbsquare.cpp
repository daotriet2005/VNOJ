#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> data;
typedef pair<ll, string> super;
#define fore(i,a,b) for (ll i=a;i<=b;++i)
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
ll dp[1005][1005],a[1005][1005],n,m;
data save[1005];
void solve()
{
    cin>>n>>m;
    ll max1=0;
    fore(i,1,n)
        fore(j,1,m)
        {
            cin>>a[i][j];
            if (n==1) dp[i][j]=1;
            else
                if (a[i][j]==a[i-1][j]) dp[i][j]=dp[i-1][j]+1;
                else dp[i][j]=1;
        }
    fore(i,1,n)
    {
        deque<int> p;
        fore(j,1,m)
        {

            save[j].fi=j;
            while (!p.empty() && a[i][p.back()]==a[i][j] && dp[i][p.back()]>=dp[i][j])
            {
                save[p.back()].se=j-1;
                max1=max(max1,min(dp[i][p.back()],save[p.back()].se-save[p.back()].fi+1));
                save[j].fi=save[p.back()].fi;
                p.pob();
            }
            if (!p.empty() && a[i][p.back()]!=a[i][j])
                while (!p.empty())
                {
                    save[p.back()].se=j-1;
                    max1=max(max1,min(dp[i][p.back()],save[p.back()].se-save[p.back()].fi+1));
                    p.pob();
                }
            p.pub(j);
        }
        while (!p.empty())
        {
            save[p.back()].se=m;
            max1=max(max1,min(dp[i][p.back()],save[p.back()].se-save[p.back()].fi+1));
            p.pob();
        }
    }
    cout<<max1<<endl;
}
int main()
{
    fast;
    solve();
    return 0;
}
