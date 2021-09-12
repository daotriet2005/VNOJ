#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long int ll;
typedef pair<ll,ll> data;
typedef vector <data> super;
data a[25],b[25];
int n,m;
super dp1,dp2;
super solve(data x[25],int n)
{
    super dp;
    for (int i=0;i<(1<<n);i++)
    {
        ll tmp=0;
        ll val=0;
        for (int j=1;j<=n;j++)
            if (i & (1<<(j-1)))
            {
                tmp+=x[j].fi;
                val+=x[j].se;
            }
        if (tmp<=m) dp.pb(data(tmp,val));
    }
    return dp;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int n1=n/2;
    int n2=n-n1;
    for (int i=1;i<=n1;i++) cin>>a[i].fi>>a[i].se;
    for (int j=n2;j<=n;j++) cin>>b[j-n2+1].fi>>b[j-n2+1].se;
    dp1=solve(a,n1); sort(dp1.begin(),dp1.end());
    dp2=solve(b,n2); sort(dp2.begin(),dp2.end());
    ll out=0;
    vector <ll> max1(dp2.size()+5);
    max1[0]=dp2[0].se;
    for (int i=1;i<dp2.size();i++)
        max1[i]=max(max1[i-1],dp2[i].se);
    int j=dp2.size()-1;
    for (int i=0;i<dp1.size();i++)
    {
        while (dp1[i].fi+dp2[j].fi>m && j>0) j--;
        if (dp1[i].fi+dp2[j].fi<=m) out=max(out,dp1[i].se+max1[j]);
    }
    cout<<out;
    return 0;
}
