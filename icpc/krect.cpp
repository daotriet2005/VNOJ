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
const ll maxN=250+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,0};
const ll base=31;
ll dp[105][105][30],n,m,k,ans;
int hcn(int x, int y, int x2, int y2)
{
    int res=0;
    forw(i,'A','Z')
        res+=(dp[x2][y2][i-'A'] - dp[x2][y-1][i-'A'] - dp[x-1][y2][i-'A'] + dp[x-1][y-1][i-'A'] > 0);
    return res;
}
void solve()
{
    cin>>n>>m>>k;
    forw(i,1,n)
    {
        vector <int> res(27,0);
        forw(j,1,m)
        {
            char x;
            cin>>x;
            res[x-'A']++;
            forw(p,'A','Z')
                dp[i][j][p-'A']=dp[i-1][j][p-'A']+res[p-'A'];
        }
    }
    forw(x1,1,n)
        forw(x2,x1,n)
        {
            int l=1,r=1;
            forw(j2,1,m)
            {
                while (l<j2 && hcn(x1,l,x2,j2)>k) l++;
                while (r<j2 && hcn(x1,r+1,x2,j2)>=k) r++;
                if (hcn(x1,l,x2,j2)==k && hcn(x1,r,x2,j2)==k)
                    ans+=(r-l+1);
            }
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
