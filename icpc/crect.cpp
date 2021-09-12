#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,pair<ll,ll> >data;
typedef pair<ll, string> super;
#define fore(i,a,b) for (ll i=a;i<=b;i++)
#define forw(i,a,b) for (ll i=a;i>=b;i--)
#define fast {ios::sync_with_stdio(false); cin.tie(0); }
#define fi first
#define se second
#define pu push
#define puf push_front
#define pub push_back
#define pof pop_front
#define pob pop_back
#define fr front
#define reset(a) memset(a,0,sizeof(a))
ll n,m,a[500][500],ans,h[500],l[500],dp[500];
ll rec(int x, int y, int z)
{
    ll out=0;
    reset(h);
    //reset(dp);
    //reset(l);
    fore(i,1,n)
    {
        stack<ll> p;
        reset(l);
        reset(dp);
        fore(j,1,m)
        {
            if (a[i][j]==x || a[i][j]==y || a[i][j]==z) h[j]+=1;
            else h[j]=0;
            while (!p.empty() && h[p.top()]>=h[j]) p.pop();
            if (p.empty()) l[j]=1;
            else l[j]=p.top()+1;
            p.pu(j);
            ll res=l[j]-1;
            if (h[j]>0)
            {
                res=l[j]-1;
                dp[j]=(j-res)*h[j]+dp[res];
                out+=dp[j];
            }
            else dp[j]=0;
        }
    }
    return out;
}
ll tinh(int x, int y, int z)
{
    return rec(x,y,z)-rec(x,x,y)-rec(y,y,z)-rec(z,z,x)+rec(x,x,x)+rec(y,y,y)+rec(z,z,z);
}
int main()
{
    fast;
    //freopen("test.inp","r",stdin);
    char x;
    cin>>n>>m;
    fore(i,1,n)
        fore(j,1,m)
        {
            cin>>x;
            a[i][j]=(x-'A'+1);
        }
    fore(i,1,3)
        fore(j,i+1,4)
            fore(k,j+1,5)
                ans+=tinh(i,j,k);
    cout<<ans;
    return 0;
}
