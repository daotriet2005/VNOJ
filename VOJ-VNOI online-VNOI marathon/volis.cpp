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
const ll oo=INT_MAX;
const ll mod=5000000;
const ll maxN=1e6+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
const ll base=31;
const int maxd=10000;
const int limit=1e5+1;
int min1[1005],n,d,x;
void solve()
{
    cin>>n>>d;
    forw(i,1,n) min1[i]=oo;
    min1[0]=-oo;
    forw(i,1,n)
    {
        cin>>x;
        x+=d;
        forb(j,i,1)
            if (min1[j-1]<=x) min1[j]=min(min1[j],max(min1[j-1],x-2*d));
    }
    forb(i,n,1)
    if (min1[i]<oo)
    {
        cout<<i<<endl;
        return;
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
