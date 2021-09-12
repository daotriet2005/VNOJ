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
const ll mod=1e9+7;
const ll maxN=2e5+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
const ll base=31;
int fen[maxN],n;
ll ans;
void update(int pos, int val)
{
    for(;pos<=n;pos+=(pos & -pos))
        fen[pos]+=val;
    return;
}
int get(int pos)
{
    int res=0;
    for(;pos>0;pos-=(pos & -pos))
        res+=fen[pos];
    return res;
}
void solve()
{
    cin>>n;
    vector<int> last(n+5,0);
    forw(i,1,n)
    {
        int x;
        cin>>x;
        ans+=get(i)-get(last[x]);
        if (last[x]!=0)
            update(last[x],-1);
        update(i,1);
        last[x]=i;
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
