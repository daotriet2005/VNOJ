//http://wolfriscodingpracticediary.blogspot.com/2018/07/voj-cutseqs.html
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
const ll maxN=1e5+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
const ll base=31;
const int maxd=10000;
const int limit=1e5+1;
ll seg[4*maxN],a[maxN],n,m,pre[maxN],ans[maxN];
void update(int id, int l, int r, int pos, ll val)
{
    if (l==r)
    {
        if (l==pos) seg[id]=val;
        return;
    }
    if (pos<l || r<pos) return;
    int mid=(l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    seg[id]=min(seg[id*2],seg[id*2+1]);
}
void solve()
{
    cin>>n>>m;
    deque<ll> p;
    int l=1;
    forw(i,1,4*n) seg[i]=oo;
    forw(i,1,n)
    {
        cin>>a[i];
        if (a[i]>m)
        {
            cout<<-1;
            return;
        }
        pre[i]=pre[i-1]+a[i];
        while (pre[i]-pre[l-1]>m && l<i) l++;
        while (!p.empty() && p.fr()<l) {
            update(1,1,n,p.fr(),oo);
            p.pof();
        }
        while (!p.empty() && a[p.back()]<=a[i]) {
            update(1,1,n,p.back(),oo);
            p.pob();
        }
        if (p.empty())
            update(1,1,n,i,ans[l-1]+a[i]);
        else
        {
            update(1,1,n,p.fr(),a[p.fr()]+ans[l-1]);
            update(1,1,n,i,a[i]+ans[p.back()]);
        }
        ans[i]=seg[1];
        p.pb(i);
    }
    cout<<ans[n];
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
