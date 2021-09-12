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
ll dp[1005][1005],n,m,out;
ll l[1005],r[1005];
void solve()
{
    cin>>n>>m;
    fore(i,1,n)
    {
        fore(j,1,m)
        {
            char x;
            cin>>x;
            if (x=='0') continue;
            dp[i][j]=dp[i-1][j]+1;
        }
    }
    fore(i,1,n)
    {
        deque<int> p;
        vector<ll> ans(n+5,0);
        fore(j,1,m)
        {
            while (!p.empty() && dp[i][p.back()]>=dp[i][j]) p.pob();
            if (p.empty()) l[j]=1;
            else l[j]=p.back()+1;
            p.pub(j);
        }
        fore(j,1,m)
        {
            int pos=l[j]-1;
            ans[j]=dp[i][j]*(j-pos)+ans[pos];
            out+=ans[j];
        }
    }
    cout<<out;
}
int main()
{
    fast;
    solve();
    return 0;
}
