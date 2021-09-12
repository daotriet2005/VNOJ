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
const ll mod=5000000;
const ll maxN=1e6+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
const ll base=31;
const int maxd=10000;
const int limit=1e5+1;
// trang thai: 0 - A wins , 1- B wins , 2 - not checked
int dp[maxN][3],n,m,k,l;
void solve()
{
    cin>>k>>l>>m;
    forw(i,0,1e6) dp[i][0]=dp[i][1]=2;
    forw(i,0,1e6)
    forw(turn,0,1)
    {
        dp[i][turn]=turn^1;
        if (i>=1)
            if (dp[i-1][turn^1]==turn) dp[i][turn]=turn;
        if (i>=k)
            if (dp[i-k][turn^1]==turn) dp[i][turn]=turn;
        if (i>=l)
            if (dp[i-l][turn^1]==turn) dp[i][turn]=turn;
    }
    while (m--)
    {
        int x;
        cin>>x;
        if (dp[x][0]==0) cout<<"A";
        else cout<<"B";
    }
}
int main()
{
    fast;
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    ll t=1; //cin>>t;
    while (t--) solve();
    return 0;
}
