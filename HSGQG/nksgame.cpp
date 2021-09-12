#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;
#define fore(i,a,b) for (ll i=a;i<=b;i++)
#define forw(i,a,b) for (ll i=a;i>=b;i--)
#define fast {ios::sync_with_stdio(false); cin.tie(0); }
#define fi first
#define se second
#define pu push
#define pb push_back
const ll oo=1e18;
const ll MOD=1e9+7;
ll x,n,a[100005],ans;
ll findgreater(ll x)
{
    ll out=oo;
    int l=1;
    int r=n;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (x+a[mid]>=0)
        {
            out=x+a[mid];
            r=mid-1;
        }
        else l=mid+1;
    }
    return out;
}
ll findless(ll x)
{
    ll out=-oo;
    int l=1;
    int r=n;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (x+a[mid]<0)
        {
            out=x+a[mid];
            l=mid+1;
        }
        else r=mid-1;
    }
    return -out;
}
int main()
{
    fast;
    cin>>n;
    fore(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    ans=oo;
    fore(i,1,n)
    {
        cin>>x;
        //ll x1=findless(x);
        //ll x2=findgreater(x);
        //cout<<x1<<" "<<x2<<endl;
        ans=min(ans,min(findless(x),findgreater(x)));
    }
    cout<<ans;
    return 0;
}
