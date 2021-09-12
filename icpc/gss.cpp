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
    const ll maxN=50000+5;
    const int tx[4]={0,0,1,-1};
    const int ty[4]={1,-1,0,1};
    const ll base=31;
    struct node
    {
        ll sum, le, ri, ans;
    };
    node seg[maxN*4];
    ll a[maxN],n,m;
    void init(int id, int l, int r)
    {
        if (l==r)
        {
            seg[id].sum=seg[id].le=seg[id].ri=seg[id].ans=a[r];
            return;
        }
        int mid=(l+r)/2;
        init(id*2,l,mid);
        init(id*2+1,mid+1,r);
        seg[id].sum=seg[id*2].sum+seg[id*2+1].sum;
        seg[id].le=max(seg[id*2].le,seg[id*2].sum+seg[id*2+1].le);
        seg[id].ri=max(seg[id*2].ri+seg[id*2+1].sum,seg[id*2+1].ri);
        seg[id].ans=max(seg[id*2].ri+seg[id*2+1].le,max(seg[id*2].ans,seg[id*2+1].ans));
        return;
    }
    node get(int id, int l, int r, int u, int v)
    {
        if (u<=l && r<=v) return seg[id];
        if (v<l || r<u) return {-oo,-oo,-oo,-oo};
        int mid=(l+r)/2;
        node trai=get(id*2,l,mid,u,v);
        node phai=get(id*2+1,mid+1,r,u,v);
        ll sum=trai.sum+phai.sum;
        ll le=max(trai.le,trai.sum+phai.le);
        ll ri=max(trai.ri+phai.sum,phai.ri);
        ll ans=max(trai.ri+phai.le,max(trai.ans,phai.ans));
        return {sum,le,ri,ans};
    }
    void solve()
    {
        cin>>n;
        forw(i,1,n) cin>>a[i];
        init(1,1,n);
        cin>>m;
        forw(i,1,m)
        {
            int u,v;
            cin>>u>>v;
            node res=get(1,1,n,u,v);
            cout<<res.ans<<endl;
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
