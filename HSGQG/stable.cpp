#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
//typedef pair<ll,ll> data;
#define fore(i,a,b) for (ll i=a;i<=b;++i)
#define forw(i,a,b) for (ll i=a;i>=b;i--)
#define fast {ios::sync_with_stdio(false); cin.tie(0); }
#define fi first
#define se second
#define pu push
#define pb push_back
#define fr front
const ll oo=1e18;
const ll MOD=1e9+7;
bool ans[505][505];
ll n,m,s,u,v,count1[10005];
vector <int> check[10005],father[10005];
ll bfs()
{
    vector <ll> min1(n+5,oo);
    queue<int> p;
    p.pu(s);
    min1[s]=0;
    count1[s]=1;
    ll ans=0;
    while (!p.empty())
    {
        ll u=p.fr();
        p.pop();
        ll res=0;
        //cout<<" // "<<u<<" "<<min1[u]<<endl;
        vector <bool> kt(n+5,false);
        for(auto v:father[u])
            if (min1[v]==min1[u]-1 && !kt[v]) {
                count1[u]+=count1[v];
                kt[v]=true;
                if (count1[u]>2) count1[u]=2;
                //cout<<v<<" "<<min1[v]<<endl;
            }
        if (count1[u]>=2) {
            ans++;
            //cout<<"// "<<u<<endl;
        }
        for(auto v:check[u])
            if (min1[u]+1<min1[v])
            {
                min1[v]=min1[u]+1;
                p.pu(v);
            }
    }
    return ans;
}
int main()
{
    fast;
    cin>>n>>m>>s;
    fore(i,1,m)
    {
        cin>>u>>v;
        check[u].pb(v);
        father[v].pb(u);
    }
    //fore(i,0,father[5].size()-1)
      //  cout<<father[5][i]<<" ";
    cout<<bfs();
    return 0;
}
