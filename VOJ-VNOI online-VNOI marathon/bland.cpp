// sarah nguyen
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
const ll maxN=1e6+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,0};
const ll base=31;
int n,m,k,a[305][305],ans,dp1[305][305],dp2[305][305],res[305];
int min1[305][305][305],max1[305][305][305];
deque<int> minx,maxx;
void push(int mi, int ma)
{
    while (minx.size() && minx.back()>mi)
        minx.pob();
    minx.pb(mi);
    while (maxx.size() && maxx.back()<ma)
        maxx.pob();
    maxx.pb(ma);
}
void pop(int mi, int ma)
{
    if (minx.fr()==mi) minx.pof();
    if (maxx.fr()==ma) maxx.pof();
}
void solve()
{
    cin>>n>>m>>k;
    forw(i,1,n)
        forw(j,1,m)
            cin>>a[i][j];
    /////////// part 1: calculate
    //// tu tren xuong, tu trai qua
    forw(x1,1,n)
        forb(x2,x1,1)
        {
            int l=1;
            minx.clear();
            maxx.clear();
            forw(r,1,m)
            {
                int mi,ma;
                if (x1==x2) mi=ma=min1[x1][x2][r]=max1[x1][x2][r]=a[x1][r];
                else
                {
                    mi=min1[x1][x2][r]=min(min1[x1-1][x2][r],a[x1][r]);
                    ma=max1[x1][x2][r]=max(max1[x1-1][x2][r],a[x1][r]);
                }
                push(mi,ma);
                while (l<=r && maxx.size() && minx.size() && maxx.fr()-minx.fr()>k)
                {
                    mi=min1[x1][x2][l];
                    ma=max1[x1][x2][l];
                    pop(mi,ma);
                    l++;
                }
                if (maxx.size() && minx.size() && maxx.fr()-minx.fr()<=k)
                    //ans=max(ans,(r-l+1)*(x2-x1+1));
                    dp1[x1][r]=max(dp1[x1][r],(r-l+1)*(x1-x2+1));
            }
        }
    //cout<<ans<<endl;
    //// tu xuong len, tu phai qua
    //ans=0;
    forb(x1,n,1)
        forw(x2,x1,n)
        {
            int r=m;
            minx.clear();
            maxx.clear();
            forb(l,m,1)
            {
                int mi,ma;
                if (x1==x2) mi=ma=min1[x1][x2][l]=max1[x1][x2][l]=a[x1][l];
                else
                {
                    mi=min1[x1][x2][l]=min(min1[x1+1][x2][l],a[x1][l]);
                    ma=max1[x1][x2][l]=max(max1[x1+1][x2][l],a[x1][l]);
                }
                push(mi,ma);
                while (l<=r && minx.size() && maxx.size() && maxx.fr()-minx.fr()>k)
                {
                    mi=min1[x1][x2][r];
                    ma=max1[x1][x2][r];
                    pop(mi,ma);
                    r--;
                }
                if (minx.size() && maxx.size() && maxx.fr()-minx.fr()<=k)
                    //ans=max(ans,(x2-x1+1)*(r-l+1));
                    dp2[x1][l]=max(dp2[x1][l],(x2-x1+1)*(r-l+1));
            }
        }
    //cout<<ans<<endl;
    /////////////////// part 2 :
    // ket qua theo duong cat ngang
    res[0]=0;
    forw(i,1,n)
    {
        res[i]=res[i-1];
        forw(j,1,m)
            res[i]=max(res[i],dp1[i][j]);
    }
    ans=res[n];
    int tmp=0;
    forb(i,n,1)
    {
        forb(j,m,1)
            tmp=max(tmp,dp2[i][j]);
        ans=max(ans,res[i-1]+tmp);
    }
    // ket qua theo duong cat doc
    res[0]=0;
    forw(j,1,m)
    {
        res[j]=res[j-1];
        forw(i,1,n)
            res[j]=max(res[j],dp1[i][j]);
    }
    tmp=0;
    ans=max(ans,res[m]);
    forb(j,m,1)
    {
        forb(i,n,1)
            tmp=max(tmp,dp2[i][j]);
        ans=max(ans,res[j-1]+tmp);
    }
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
// note :
// part 2 co the fen2d de lay anwser nhanh hon
