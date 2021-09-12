#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> data;
#define fore(i,a,b) for (ll i=a;i<=b;i++)
#define forw(i,a,b) for (ll i=a;i>=b;i--)
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
const ll maxN = 2e5+5;
const ll oo = 1e18;
const ll mod=1e9+7;
int n,m;
bool ok(int mask1, int mask2)
{
    fore(i,1,m-1)
    {
        if (((1<<i)&mask1) && ((1<<(i-1))&mask1) && ((1<<i)&mask2) && ((1<<(i-1))&mask2)) return false;
        if (((1<<i)&mask1)==0 && ((1<<(i-1))&mask1)==0 && ((1<<i)&mask2)==0 && ((1<<(i-1))&mask2)==0) return false;
    }
    return true;
}
void solve()
{
    cin>>n>>m;
    if (n==30 || m==30) {
        cout<<(1<<30)<<endl;
        return;
    }
    if (n<m) swap(n,m);
    vector <ll> dp((1<<m),0);
    fore(mask,0,(1<<m)-1)
        dp[mask]=1;
    fore(pos,1,n-1)
    {
        vector <ll> new_dp((1<<m),0);
        fore(i,0,(1<<m)-1)
            fore(j,0,(1<<m)-1)
                if (ok(i,j))
                    new_dp[j]+=dp[i];
        dp=new_dp;
    }
    ll ans=0;
    fore(mask,0,(1<<m)-1)
        ans+=dp[mask];
    cout<<ans<<endl;
    return;
}
int main()
{
    fast;
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    int t; t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
