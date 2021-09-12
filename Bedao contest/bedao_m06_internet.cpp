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
const ll mod=727355608;
const ll maxN=1e6+5;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,0};
const ll base=31;
ll s,a[4],ans[maxN];
void solve()
{
    cin>>s;
    ll odd=0, ttl=0;
    forw(i,1,3)
    {
        cin>>a[i];
        ttl+=a[i];
        odd+=(a[i]%2);
    }
    if (s==1 && !a[0] && !a[1] && !a[2])
    {
        cout<<0;
        return;
    }
    if (odd>1 || (odd==1 && !(s%2))) {
    cout<<"Bedao!"<<endl;
    return;
    }
    forw(i, 1, 3)
    if (a[i]%2)
    {
        ans[(s + 1) / 2] = i;
        --a[i];
        --ttl;
        break;
    }
    int space =(s/2)*2;
    bool ok = false;
    forw(i,1,s/2) {
    if (ok && space-2>= ttl)
    {
      ans[i]=ans[s-i+1] = 0;
      space-=2;
      continue;
    }
    if (a[1]>1)
    {
        ans[i]=ans[s-i+1]=1;
        a[1]-=2;
    }
    else
        if (a[2]> 1)
        {
            ans[i]=ans[s-i+1]=2;
            a[2]-=2;
        }
        else
            if (a[3] > 1)
            {
                ans[i]=ans[s-i+1]=3;
                a[3]-=2;
            }
            else
                ans[i]=ans[s-i+1]=0;
    ok=true;
    space-=2;
    ttl-=2;
    }

    ll ret=0;
    ll base=1;
    ok=false;
    forw(i, 1, s) {
    if (!ok && !ans[i]) {
        cout<<"Bedao!"<<endl;
        return;
    }
    if (ans[i]) ok=true;
    ret=(ret%mod+(ans[i]%mod*base%mod)%mod)%mod;
    base=(base%mod*4)%mod;
    }
    cout<<ret<<endl;
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
