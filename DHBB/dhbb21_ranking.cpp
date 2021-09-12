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
data a[2005],b[2005];
int n;
bool check(int a1, int a2, int a3, int b1, int b2, int b3)
{
    if (a1>b1 || (a1==b1-1 && a2==b1-1 && a3>b2 && (b3<=a3-1 && b2<=a3-1))) return true;
    if (a1<b1) return false;
    if (a2>b2 || (a2==b2-1 && a3==b2-1)) return true;
    if (a2<b2) return false;
    if (a3<b3) return false;
    if (a3>b3) return true;
    return true;
}
bool check1(int a1, int a2, int a3, int b1, int b2, int b3)
{
    if (a1>b1 || (a1==b1-1 && a2==b1-1 && a3>b2 && (b3<=a3-1 && b2<=a3-1))) return true;
    if (a1<b1) return false;
    if (a2>b2 || (a2==b2-1 && a3==b2-1)) return true;
    if (a2<b2) return false;
    if (a3<b3) return false;
    if (a3>b3) return true;
    return false;
}
void solve()
{
    cin>>n;
    forw(i,1,n) cin>>a[i].fi;
    forw(i,1,n) {
        cin>>a[i].se;
        data res=a[i];
        a[i].fi=max(res.fi,res.se);
        a[i].se=min(res.fi,res.se);
        b[i]=a[i];
    }
    //cout<<check(7,7,2,8,1,1)<<endl;
    sort(b+1,b+1+n);
    forw(i,1,n)
    {
        // best
        int dem=2;
        bool ok=true;
        int ans=0;
        forb(j,n,1)
        {
            if (dem>n) break;
            if (b[j].fi==a[i].fi && b[j].se==a[i].se && ok) {
                ok=false;
                //if (i==9 || i==10) cout<<j<<endl;
            }
            else
            {
                vector <int> res={dem,b[j].fi,b[j].se};
                sort(all(res));
                while (dem<n && !check(res[2],res[1],res[0],a[i].fi,a[i].se,1)) {
                    dem++;
                    res={dem,b[j].fi,b[j].se};
                    sort(all(res));
                }
                //if (i==9)
                    //cout<<j<<" / "<<dem<<" "<<res[2]<<" "<<res[1]<<" "<<res[0]<<" "<<a[i].fi<<" "<<a[i].se<<endl;
                if (dem<=n && check(res[2],res[1],res[0],a[i].fi,a[i].se,1)) {
                    ans++;
                    //if (i==9) cout<<"yes "<<ans<<endl;
                }
                dem++;
            }
        }
        cout<<n-ans<<" ";
        ///////////////////////
        // worst
        dem=n-1;
        ok=true;
        ans=0;
        forw(j,1,n)
        {
            if (dem<1) break;
            if (b[j].fi==a[i].fi && b[j].se==a[i].se && ok) ok=false;
            else
            {
                vector <int> res={dem,b[j].fi,b[j].se};
                sort(all(res));
                while (dem>1 && check(res[2],res[1],res[0],n,a[i].fi,a[i].se)) {
                    dem--;
                    res={dem,b[j].fi,b[j].se};
                    sort(all(res));
                }
                //cout<<res[2]<<" "<<res[1]<<" "<<res[0]<<" "<<a[i].fi<<" "<<a[i].se<<endl;
                if (dem>=1 && !check(res[2],res[1],res[0],n,a[i].fi,a[i].se)) ans++;
                dem--;
            }
        }
        cout<<ans+1<<endl;
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
