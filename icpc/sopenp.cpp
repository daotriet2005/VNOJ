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
const ll maxN=2e6+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,0};
const ll base=31;
int n,L,R,a[maxN];
void solve()
{
    cin>>n>>R>>L; // R: right pointer's limit , L: left pointer's limit  => (L >= R)
    int l=1,r=1;
    map<int, int> trai,phai;
    ll ans=0;
    forw(i,1,n)
    {
        cin>>a[i];
        trai[a[i]]++;
        phai[a[i]]++;
        while (l<i && trai.size()>L)
        {
            trai[a[l]]--;
            if (trai[a[l]]==0)
                trai.erase(a[l]);
            l++;
        }
        while (r<=i && phai.size()>=R)
        {
            phai[a[r]]--;
            if (phai[a[r]]==0)
                phai.erase(a[r]);
            r++;
        }
        if (L>=trai.size() && R>phai.size())
            ans+=r-l;
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
