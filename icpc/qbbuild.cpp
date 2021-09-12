#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pi;
typedef pair<ll, pair<ll, ll> > pii;
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
const int base=31;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
// custom
const ll maxN=105;
/////
ll node[5],dp[maxN][maxN],ans,n,u,v,c;
void solve()
{
    cin>>n;
    cin>>node[1]>>node[2]>>node[3]>>node[4];
    sort(node+1,node+5);
    forw(i,1,n)
        forw(j,1,n)
        if (i!=j) dp[i][j]=oo;
    while (cin>>u>>v>>c)
        dp[u][v]=dp[v][u]=c;
    forw(k,1,n)
        forw(i,1,n)
            forw(j,1,n)
                if (dp[i][k]+dp[k][j]<dp[i][j])
                    dp[i][j]=dp[i][k]+dp[k][j];
    ans=oo;
    do
    {
        //cout<<node[1]<<" "<<node[2]<<" "<<node[3]<<" "<<node[4]<<endl;
        forw(i,1,n)
            forw(j,1,n)
                ans=min(ans,dp[node[1]][i]+dp[node[2]][i]+dp[node[3]][j]+dp[node[4]][j]+dp[i][j]);
    }
    while (next_permutation(node+1,node+5));
    cout<<ans<<endl;
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
