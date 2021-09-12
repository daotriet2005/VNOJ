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
const ll mod=1000001;
const ll maxN=3e4+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,1};
const ll base=31;
const int maxd=10000;
int n,m,limit,fen[175][maxd+1],a[maxN];
void update(int x, int y,int val)
{
    while (x<=174)
    {
        int v=y;
        while (v<=maxd)
        {
            fen[x][v]+=val;
            v+=(v & -v);
        }
        x+=(x & -x);
    }
    return;
}
int get(int x, int y)
{
    int res=0;
    while (x>0)
    {
        int v=y;
        while (v>0)
        {
            res+=fen[x][v];
            v-=(v & -v);
        }
        x-=(x & -x);
    }
    return res;
}
int rec(int x11, int y11, int x22, int y22)
{
    if (x11>x22 || y11>y22) return 0;
    return  get(x22,y22)+get(x11-1,y11-1)-get(x22,y11-1)-get(x11-1,y22);
}
int main()
{
    fast;
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    int x,y,z,l,r,k,q;
    cin>>n;
    m=sqrt(n);
    forw(i,1,n) {
        cin>>a[i];
        update(i/m-(i%m==0)+1,a[i],1);
    }
    cin>>q;
    forw(i,1,q)
    {
        cin>>x;
        if (x==0)
        {
            cin>>y>>z;
            update(y/m-(y%m==0)+1,a[y],-1);
            a[y]=z;
            update(y/m-(y%m==0)+1,a[y],1);
            continue;
        }
        cin>>l>>r>>k;
        int L=l/m-(l%m==0)+1;
        int R=r/m-(r%m==0)+1;
        int ans=0;
        if (R==L)
        {
            forw(j,l,r)
                ans+=(a[j]>k);
            cout<<ans<<endl;
            continue;
        }
        R--;
        L++;
        ans=rec(L,k+1,R,maxd);
        forw(j,l,(L-1)*m)
            ans+=(a[j]>k);
        forw(j,R*m+1,r)
            ans+=(a[j]>k);
        cout<<ans<<endl;
    }
    return 0;
}
