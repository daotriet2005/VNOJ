#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> data;
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
int num1[200005],min1[200005],dem1,n,m,cnt,nen[200010],ans;
vector <int> check[200005],check1[200005],save,father[200005];
stack <int> p,xoa;
data a[200005];
void visit1(int u)
{
    p.pu(u);
    num1[u]=min1[u]=++dem1;
    for(auto v:check[u])
    {
        if (!num1[v])
        {
            visit1(v);
            min1[u]=min(min1[u],min1[v]);
        }
        else min1[u]=min(min1[u],num1[v]);
    }
    if (num1[u]==min1[u])
    {
        save.pb(u);
        while (p.top()!=u)
        {
            nen[p.top()]=u;
            min1[p.top()]=num1[p.top()]=1e9;
            p.pop();
        }
        nen[u]=u;
        min1[u]=num1[u]=1e9;
        p.pop();
    }
}
void kiemtra()
{
    vector <int> start,finish;
    for(auto i:save)
    {
        if (father[i].size()==0) start.pb(i);
        if (check1[i].size()==0) finish.pb(i);
    }
    if (start.size()==1 && finish.size()==1)
    {
        cout<<"YES"<<endl;
        cout<<finish[0]<<" "<<start[0];
    }
    else cout<<"NO";
}
int main()
{
    fast;
    cin>>n>>m;
    fore(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        a[i].fi=u;
        a[i].se=v;
        check[u].pb(v);
    }
    fore(i,1,n)
    if (!num1[i]) visit1(i);
    fore(i,1,m)
    {
        int u,v;
        u=a[i].fi;
        v=a[i].se;
        if (nen[u]==nen[v]) continue;
        u=nen[u];
        v=nen[v];
        check1[u].pb(v);
        father[v].pb(u);
    }
    kiemtra();
    return 0;
}
