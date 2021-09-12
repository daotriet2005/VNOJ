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
const ll oo=1e18;
const ll mod=5000000;
const int base=31;
const ll maxN=1e6+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
const int maxd=10000;
const int limit=1e5+1;
bool dp1[3][505][505],dp2[3][505][505],a[505][505];
ll n,x,y,k,ans;
void solve()
{
    cin>>n>>k;
    forw(i,1,k)
    {
        cin>>x>>y;
        a[x][y]=true;
    }
    //dp - res - x - y;
    dp1[0][1][1]=dp2[0][1][n]=true;
    forw(res,1,1000)
    {
        int now=res%2;
        int pre=(res-1)%2;
        forw(i,1,res+1)
            forw(j,1,res+1)
            {
                if (a[i][j])
                {
                    dp1[now][i][j]=false;
                    continue;
                }
                if (dp1[pre][i-1][j-1] || dp1[pre][i-1][j] || dp1[pre][i][j-1])
                    dp1[now][i][j]=true;
                else
                    dp1[now][i][j]=false;
            }
        forw(i,1,res+1)
            forb(j,n,n-res)
            {
                if (a[i][j])
                {
                    dp2[now][i][j]=false;
                    continue;
                }
                if (dp2[pre][i-1][j+1] || dp2[pre][i-1][j] || dp2[pre][i][j+1])
                {
                    dp2[now][i][j]=true;
                    if (dp1[now][i][j]) ans=res;
                }
                else
                    dp2[now][i][j]=false;
            }
        if (ans>0) break;
    }
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
