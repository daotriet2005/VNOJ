#include <bits/stdc++.h>
using namespace std;
int n,dp[100005],a[100005],dp1[100005];
vector <int> max1;
#define pb push_back
int find_max(int x,int l,int r)
{
    int out=0;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (max1[mid]<x)
        {
            l=mid+1;
            out=mid;
        }
        else r=mid-1;
    }
    return out;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=0;i<=n+5;i++) max1.pb(1e9+1);
    max1[0]=0;
    int l=0;
    int r=0;
    for (int i=1;i<=n;i++)
    {
        int p=find_max(a[i],l,r);
        dp[i]=p+1;
        max1[p+1]=min(a[i],max1[p+1]);
        r=max(r,p+1);
    }
    for (int i=0;i<=n+5;i++) max1[i]=1e9+1;
    max1[0]=0;
    l=0;
    r=0;
    for (int i=n;i>=1;i--)
    {
        int p=find_max(a[i],l,r);
        dp1[i]=p+1;
        max1[p+1]=min(max1[p+1],a[i]);
        r=max(r,p+1);
    }
    int out=0;
    for (int i=1;i<=n;i++)
        out=max(out,min(dp[i],dp1[i])*2-1);
    cout<<out;
    return 0;
}
