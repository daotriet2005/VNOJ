#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
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
const ll MOD=111539786;
const ll maxN=2e5+5;
struct data
{
    ll a[3][3];
};
data multiply(data a, data b)
{
    data ans;
    fore(i,1,2)
        fore(j,1,2)
        {
            ans.a[i][j]=0;
            fore(k,1,2)
                ans.a[i][j]=(ans.a[i][j]+ (a.a[i][k]*b.a[k][j])%MOD)%MOD;
        }
    return ans;
}
data power(data a, ll n)
{
    data ans;
    ans.a[1][1]=ans.a[1][2]=1;
    ans.a[2][1]=ans.a[2][2]=0;
    while (n>0)
    {
        if (n%2) ans=multiply(ans,a);
        n/=2;
        a=multiply(a,a);
    }
    return ans;
}
int main()
{
    fast;
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    int t;
    cin>>t;
    data a;
    a.a[1][1]=1;
    a.a[1][2]=1;
    a.a[2][1]=1;
    a.a[2][2]=0;
    while (t--)
    {
        ll n;
        cin>>n;
        data b=power(a,n-1);
        cout<<b.a[1][1]<<endl;
    }
    return 0;
}
