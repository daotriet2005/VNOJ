#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,pair<ll,ll> >data;
#define fore(i,a,b) for (ll i=a;i<=b;++i)
#define forw(i,a,b) for (ll i=a;i>=b;i--)
#define fast {ios::sync_with_stdio(false); cin.tie(0); }
#define fi first
#define se second
#define pu push
#define pb push_back
#define fr front
const int tx[4]={-1,1,-1,1};
const int ty[4]={-1,-1,1,1};
const ll oo=1e18;
const ll MOD=1e9+7;
ll n,m,sx,sy,fx,fy,a[205][205];
bool kt[205][205];
bool check(int x, int y)
{
    if (1<=x && x<=n)
        if (1<=y && y<=n)
            if (!a[x][y]) return true;
    return false;
}
ll bfs(int x, int y)
{
    queue<data> p;
    kt[x][y]=true;
    p.pu({0,{x,y}});
    while (!p.empty())
    {
        x=p.fr().se.fi;
        y=p.fr().se.se;
        ll val=p.fr().fi;
        p.pop();
        if (x==fx && y==fy) return val;
        //cout<<"// "<<x<<" "<<y<<endl;
        fore(i,0,3)
        {
            int xx=x+tx[i];
            int yy=y+ty[i];
            while (check(xx,yy))
            {
                if (kt[xx][yy]) {
                    xx+=tx[i];
                    yy+=ty[i];
                    continue;
                }
                //cout<<xx<<" "<<yy<<endl;
                kt[xx][yy]=true;
                p.pu({val+1,{xx,yy}});
                xx+=tx[i];
                yy+=ty[i];
            }
        }
    }
    return -1;
}
int main()
{
    fast;
    cin>>n>>m>>sx>>sy>>fx>>fy;
    fore(i,1,m)
    {
        int x,y;
        cin>>x>>y;
        a[x][y]=true;
    }
    cout<<bfs(sx,sy);
    return 0;
}
