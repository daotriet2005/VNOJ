#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> data;
typedef pair<int, pair<int, int> > pii;
#define forw(i,a,b) for (int i=a;i<=b;i++)
#define forb(i,a,b) for (int i=a;i>=b;i--)
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
ll dp[20][12][3];
ll solve(ll x)
{
    if (x==-1) return 0;
    string s=to_string(x);
    int n=s.length();
    s=' '+s;
    memset(dp,0,sizeof dp);
    // 0: already less than limit
    // 1: being equal to limit
    forw(i,0,9)
    if (s[1]-'0'>i)
        dp[1][i][0]=1;
    else
        if (s[1]-'0'==i)
            dp[1][i][1]=1;
    forw(i,2,n)
    {
        forw(j,0,9)
        {
            forw(k,0,9)
            {
                if (j==3 && k==1) continue;
                dp[i][j][0]+=dp[i-1][k][0];
                if (s[i]-'0'>j)
                    dp[i][j][0]+=dp[i-1][k][1];
                else
                    if (s[i]-'0'==j)
                        dp[i][j][1]+=dp[i-1][k][1];
            }
        }
    }
    ll ans=0;
    forw(i,0,9)
        ans+=dp[n][i][0]+dp[n][i][1];
    return ans;
}
int main()
{
    fast;
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    ll t=1; //cin>>t;
    ll l,r;
    while (cin>>l>>r)
    {
        cout<<solve(r)-solve(l-1)<<endl;
    }
    return 0;
}
