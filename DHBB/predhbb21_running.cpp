#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> data;
#define fore(i,a,b) for (ll i=a;i<=b;i++)
#define forw(i,a,b) for (ll i=a;i>=b;i--)
#define fast {ios::sync_with_stdio(false); cin.tie(0); }
#define fi first
#define se second
#define pu push
#define pb push_back
#define fr front
const ll oo=1e10;
const ll MOD=1e9+7;
ll n,s,t,min1[100005];
ll father[100005];
vector <data>check[100005];
void bfs(int x)
{

    queue<data> p;
    p.pu({oo,x});
    min1[x]=oo;
    father[x]=x;
    while (!p.empty())
    {
        ll val=p.fr().fi;
        int u=p.fr().se;
        p.pop();
        if (u==t) return;
        for(auto res:check[u])
        {
            ll z=res.fi;
            int v=res.se;
            if (!father[v])
            {
                z=min(val,z);
                min1[v]=z;
                father[v]=u;
                p.pu({z,v});
            }
        }
    }
}
ll flow()
{
    int v=t;
    int fin=t;
    ll val=min1[t];
    do
    {
        int u=father[v];
        if (u==s) fin=v;
        v=u;
    }while (v!=s);
    int res=check[s].size();
    fore(i,0,res-1)
    if (check[s][i].se==fin) check[s][i].fi-=val;
    ll max1=0;
    ll max2=0;
    res=check[t].size();
    fore(i,0,res-1)
    if (check[t][i].se==father[t]) check[t][i].fi-=val;
    for(auto res:check[t])
    if (res.se!=s)
        max2=max(max2,res.fi);
    for(auto res:check[s])
    if (res.se!=t)
        max1=max(max1,res.fi);
    return min(max1,max2)+val;
}
int main()
{
    fast;
    cin>>n>>s>>t;
    fore(i,1,n-1)
    {
        int x,y,z;
        cin>>x>>y>>z;
        check[x].pb({z,y});
        check[y].pb({z,x});
    }
    bfs(s);
    cout<<flow();
    return 0;
}
