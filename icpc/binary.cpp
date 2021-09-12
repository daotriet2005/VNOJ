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
#define pb push_back
#define pof pop_front
#define pob pop_back
#define fr front
#define all(a) a.begin(),a.end()
const ll oo=1e18;
const ll MOD=1e9+7;
const ll maxN=2e5+5;
ll a;
ll dp[50][3][50][3],v;
string bin(ll x)
{
    string s="";
    bool kt=false;
    forw(i,31,0)
    {
        if (x & (1<<i))
        {
            s+='1';
            kt=true;
        }
        else
            if (kt) s+='0';
    }
    return s;
}
void reset()
{
    fore(i,1,32)
        fore(j,0,1)
            fore(p,0,31)
                dp[i][j][p][0]=dp[i][j][p][1]=0;
}
ll solve(string s)
{
    //cout<<s<<endl;
    reset();
    int n=s.length();
    s=' '+s;
    dp[1][1][0][0]=1;
    fore(i,2,n)
    {
        dp[i][1][0][1]=1;
        fore(j,0,1)
            fore(k,0,1)
                fore(p,0,min((ll)31,v))
                {
                    if (j==0)
                        dp[i][j][p+1][1]+=dp[i-1][k][p][1];
                    else
                        dp[i][j][p][1]+=dp[i-1][k][p][1];

                    if (s[i]-'0'>j)
                        if (j==0)
                            dp[i][j][p+1][1]+=dp[i-1][k][p][0];
                        else
                            dp[i][j][p][1]+=dp[i-1][k][p][0];
                    else
                        if (s[i]-'0'==j)
                            if (j==0)
                                dp[i][j][p+1][0]+=dp[i-1][k][p][0];
                            else
                                dp[i][j][p][0]+=dp[i-1][k][p][0];
                }
    }
    ll ans=0;
    fore(i,0,1)
        ans+=dp[n][i][v][0]+dp[n][i][v][1];
    if (v==1) ans++;
    return ans;
}
int main()
{
    fast;
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    while (cin>>a>>v)
    {
        if (v>31) cout<<0<<endl;
        else cout<<solve(bin(a))<<endl;
    }
    return 0;
}
