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
int pa[maxN][20],seg[4*maxN],n,m,st[maxN],en[maxN],dem,take;
bool a[maxN];
vector <int> check[maxN];
void dfs(int u, int father)
{
    st[u]=++dem;
    pa[u][0]=father;
    forw(i,1,18)
        pa[u][i]=pa[pa[u][i-1]][i-1];
    for(int v:check[u])
    if (v!=father)
        dfs(v,u);
    en[u]=dem;
}
void update(int id, int l, int r, int u, int v, int val)
{
    if (u<=l && r<=v)
    {
        //cout<<"// "<<l<<" "<<r<<" "<<u<<" "<<v<<endl;
        seg[id]+=val;
        return;
    }
    if (v<l || r<u) return;
    int mid=(l+r)/2;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
}
void get(int id, int l, int r, int pos)
{
    /*if (l==r)
    {
        if (l==pos)
            take=seg[id];
        return;
    }*/
    if (pos<l || r<pos) return;
    take+=seg[id];
    if (l==r) return;
    int mid=(l+r)/2;
    get(id*2,l,mid,pos);
    get(id*2+1,mid+1,r,pos);
}
void solve()
{
    cin>>n>>m;
    forw(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        check[u].pb(v);
        check[v].pb(u);
    }
    dfs(1,1);
    // a: 0-white, 1-black
    forw(i,1,m)
    {
        int res,u;
        cin>>res>>u;
        if (res==0)
        {
            if (a[u])
                update(1,1,n,st[u],en[u],-1);
            else
                update(1,1,n,st[u],en[u],1);
            a[u]^=1;
        }
        else
        {
            forb(i,18,0)
            {
                take=0;
                get(1,1,n,st[pa[u][i]]);
                if (take>0)
                    u=pa[u][i];
            }
            take=0;
            get(1,1,n,st[u]);
            //cout<<take<<" ";
            if (take>0)
                cout<<u<<endl;
            else cout<<-1<<endl;
        }
    }
    //forw(i,1,n)
     //   cout<<st[i]<<" "<<en[i]<<endl;
}
int main()
{
    fast;
    //freopen("test.inp","r",stdin);
   // freopen("test.out","w",stdout);
    ll t=1; //cin>>t;
    while (t--) solve();
    return 0;
}
