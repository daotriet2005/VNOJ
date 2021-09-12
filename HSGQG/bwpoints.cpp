#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> data;
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
int main()
{
    fast;
    int n;
    int a1,b1,new_a,new_b,a[100005],b[100005];
    cin>>n;
    fore(i,1,n) cin>>a[i]; sort(a+1,a+1+n);
    fore(i,1,n) cin>>b[i]; sort(b+1,b+1+n);
    a1=b1=1;
    int ans=0;
    bool ok=true;
    while (ok)
    {
        ans++;
        //bool kt1,kt2;
        //k1=kt2=false;
        new_a=a1+1;
        new_b=b1+1;
        //cout<<new_a<<" "<<new_b<<" "<<ans<<endl;
        if (new_a>n || new_b>n) break;
        while (a[new_a]<=b[b1] && new_a<n)
            new_a++;
        while (b[new_b]<=a[a1] && new_b<n)
            new_b++;
        if (a[new_a]<=b[b1] || b[new_b]<=a[a1]) break;
        a1=new_a;
        b1=new_b;
        //cout<<new_a<<" "<<new_b<<endl;
    }
    cout<<ans;
    return 0;
}
