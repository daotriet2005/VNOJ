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
bool ans[505][505];
ll dp[505][505],n,res,x;
void solve()
{
    cin>>n;
    fore(i,1,n)
    {
        res=0;
        fore(j,1,n)
        {
            cin>>x;
            res+=x;
            dp[i][j]=dp[i-1][j]+res;
            ans[i][j]=false;
        }
    }
    fore(i,1,n)
    {
        fore(j,1,n)
        {
            ll dong=dp[i][j]-dp[i-1][j];
            ll cot=dp[i][j]-dp[i][j-1];
            if (dong%2==0 && !ans[i-1][j]) ans[i][j]=true;
            if (cot%2==0 && !ans[i][j-1]) ans[i][j]=true;
        }
    }
    if (ans[n][n]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main()
{
    fast;
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}
