#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,pair<ll,ll> > data1;
typedef pair<ll, ll> data;
#define fore(i,a,b) for (ll i=a;i<=b;++i)
#define forw(i,a,b) for (ll i=a;i>=b;i--)
#define fast {ios::sync_with_stdio(false); cin.tie(0); }
#define fi first
#define se second
#define pu push
#define pb push_back
#define fr front
vector <ll> min1, min2,min3;
vector <data1> check[1000];
vector <data> check1[1000];
ll n,m;
bool have[1005];
pair< pair<ll,ll> , pair<ll,ll> > a[30005];
vector<ll> dijk1(vector<ll> min1, ll s)
{
    priority_queue <data, vector <data> , greater<data>  > p;
    min1.assign(n+5,1e9);
    min1[s]=0;
    p.pu({0,s});
    while (!p.empty())
    {
        ll u=p.top().se;
        ll val=p.top().fi;
        p.pop();
        if (val>min1[u]) continue;
        for(auto res:check[u])
        {
            ll v=res.fi;
            ll time=res.se.fi;
            if (val+time<min1[v])
            {
                min1[v]=val+time;
                p.pu({min1[v],v});
            }
        }
    }
    return min1;
}

bool dijk2(ll x)
{
    min2.assign(n+5,1e9);
    priority_queue <data, vector <data>, greater<data> > p;
    p.pu({0,1});
    min2[1]=0;
    while (!p.empty())
    {
        ll u=p.top().se;
        ll val=p.top().fi;
        p.pop();
        if (val>x) continue;
        if (have[u]){
            val=0;
            min2[u]=0;
        }
        if (u==n) return true;
        //if (u==3) cout<<" /// "<<val<<endl;
        if (val>min2[u]) continue;
        for(auto res:check1[u])
        {
            ll v=res.se;
            ll dodai=res.fi;
            //cout<<u<<" "<<v<<" "<<val<<" "<<dodai<<" "<<min2[v]<<endl;
            if (val+dodai<min2[v] && val+dodai<=x)
            {
                if (have[v])min2[v]=0;
                else min2[v]=val+dodai;
                p.pu({min2[v],v});
            }
        }
    }
    //fore(i,1,n)
      //  cout<<i<<" "<<min2[i]<<endl;
    return false;
}
int main()
{
    fast;
    cin>>n;
    fore(i,1,n) cin>>have[i];
    have[n]=1;
    cin>>m;
    ll u,v,t,c;
    fore(i,1,m)
    {
        cin>>u>>v>>t>>c;
        check[u].pb({v,{t,c}});
        check[v].pb({u,{t,c}});
        a[i]={{u,v},{t,c}};
    }
    min1=dijk1(min1,1);
    min3=dijk1(min3,n);
   // fore(i,1,n)
     //  cout<<i<<" "<<min3[i]<<endl;
    fore(i,1,m)
    {
        u=a[i].fi.fi;
        v=a[i].fi.se;
        t=a[i].se.fi;
        c=a[i].se.se;
        if (min1[u]+min3[v]+t==min1[n] || min1[v]+t+min3[u]==min1[n])
        {
            check1[u].pb({c,v});
            check1[v].pb({c,u});
            //cout<<u<<" "<<v<<endl;
        }
    }
    ll l=0;
    ll r=1e9;
    ll ans=0;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (dijk2(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans;
    return 0;
}
