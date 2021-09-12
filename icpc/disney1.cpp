#include <bits/stdc++.h>
using namespace std;
#define fastIO {ios::sync_with_stdio(false); cin.tie(0); }
#define pu push
#define pb push_back
#define fi first
#define se second
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll,ll> data;
ll n,a[500][500],dp[500][500],out;
int main()
{
    fastIO;
    cin>>n;
    for (int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            dp[i][j]=1e9;
            //if (i==1) dp[0][j]=dp[i][j];
           // if (j==1) dp[i][0]=dp[i][j];
        }
    dp[1][1]=dp[1][0]=dp[0][1]=0;
    out=1e9;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=i;j++)
        {
            dp[i+1][i]=min(dp[i+1][i],dp[i][j]+a[j][i+1]);
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]+a[i][i+1]);
            dp[i][j+1]=min(dp[i][j+1],dp[i][j]+a[j][j+1]);
        }
    for (int i=1;i<=n;i++)
    {
        out=min(out,dp[n][i]+a[n][1]+a[i][1]);
        //for (int j=1;j<=n;j++)
          //  cout<<dp[i][j]<<" ";
        //cout<<endl;
    }
    if (out==1e9) cout<<0;
    else cout<<out;
    return 0;
}
