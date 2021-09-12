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
const ll maxN=1e3+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,0};
const ll base=31;
// h: height of (i,j)
// w: height of water of (i,j)
int h[maxN][maxN],w[maxN][maxN],n,m;
bool border(int x, int y)
{
    forw(i,0,3)
    {
        int xx=x+tx[i];
        int yy=y+ty[i];
        if (w[xx][yy]!=0) return true;
    }
    return false;
}
void bfs(int x, int y, int val)
{
    queue<data> p;
    p.pu({x,y});
    w[x][y]=val;
    while (!p.empty())
    {
        x=p.fr().fi;
        y=p.fr().se;
        p.pop();
        forw(i,0,3)
        {
            int xx=x+tx[i];
            int yy=y+ty[i];
            if (!w[xx][yy] && h[xx][yy]<=val)
            {
                w[xx][yy]=val;
                p.pu({xx,yy});
            }
        }
    }
}
void solve()
{
    cin>>n>>m;
    forw(i,1,n)
        w[i][0]=w[i][m+1]=-1;
    forw(j,1,m)
        w[0][j]=w[n+1][j]=-1;
    priority_queue<pii, vector <pii>, greater<pii> > p;
    forw(i,1,n)
        forw(j,1,m)
        {
            cin>>h[i][j];
            p.pu({h[i][j],{i,j}});
        }
    while (!p.empty())
    {
        int hei=p.top().fi;
        int x=p.top().se.fi;
        int y=p.top().se.se;
        p.pop();
        if (!w[x][y] && border(x,y))
            bfs(x,y,hei);
    }
    ll ans=0;
    forw(i,1,n)
        forw(j,1,m)
            ans+=max(0,w[i][j]-h[i][j]);
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
// idea:
// mình sẽ loang từ các ô ở bìa trước, loang ra các ô có độ cao nhỏ hơn hoặc bằng mà chưa được visit
// gán giá trị mực nước = chiều cao của ô ở bìa đó, vì nếu có cách nào đó mà làm mưc nước thấp hơn thì đã được loang trước đó vì visit lần lượt theo độ cao tăng dần
// vì ở thời điểm đang xét độ cao x, thì tất cả các ô chưa xét sẽ có MỰC NƯỚC >=x, vì nếu có ô có độ cao <x, thì xung quanh nó đều đã được bao phủ bởi các ô có độ cao >=x, không thì nó đã được visit rồi
// note: ô ở bìa là ô mà có 1 ô kề cạnh là ngoài map hoặc là ô đã được visit
