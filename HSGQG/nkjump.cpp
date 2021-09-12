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
#define fr front
const ll oo=1e18;
const ll MOD=1e9+7;
ll n,a[1005],ans;
int main()
{
    fast;
    cin>>n;
    map<int, ll> p;
    fore(i,1,n) cin>>a[i];sort(a+1,a+1+n);
    fore(i,1,n)
    {
        if (i<=2) p[a[i]]=1;
        else
        {
            //cout<<"//"<<endl;
            ll res=1;
            forw(j,i,1)
            if (a[i]!=a[j]*2)
            {
                if (p[a[i]-a[j]]>0)
                    res=max(res,p[a[j]]+1);
            }
            else
                if (a[j-1]==a[j] && j>1)
                    res=max(res,p[a[j]]+1);
            p[a[i]]=res;
            //cout<<p[a[i]]<<endl;
        }
        ans=max(ans,(ll)p[a[i]]);
    }
    cout<<ans;
    return 0;
}
