#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> data;
typedef pair<int, pair<int, int> > pii;
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
const ll maxN=1e5+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,0};
const ll base=31;
vector <int> pos;
int n,m,k,x;
ll ans,dp[505][505];
ll m3(int x, int y, int x2, int y2)
{
    return dp[x2][y2] - dp[x2][y-1] - dp[x-1][y2] + dp[x-1][y-1];
}
void solve()
{
    cin>>n>>m>>k;
    forw(i,1,n)
    {
        ll res=0;
        forw(j,1,m)
        {
            cin>>x;
            res+=x;
            dp[i][j]=dp[i-1][j]+res;
        }
    }
    ans=oo;
    forw(x1,1,n)
        forw(x2,x1,n)
        {
            int l=1;
            forw(r,1,m)
            {
                while (l<r && m3(x1,l+1,x2,r)>=k) l++;
                if (m3(x1,l,x2,r)>=k)
                    if (ans>(x2-x1+1)*(r-l+1))
                    {
                        ans=(x2-x1+1)*(r-l+1);
                        pos={x1,l,x2,r};
                    }
            }
        }
    if (ans==oo) cout<<-1;
    else
    {
        cout<<ans<<endl;
        forw(i,0,3)
            cout<<pos[i]<<" ";
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
