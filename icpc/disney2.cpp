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
    //cout<<"///////////"<<endl;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        if (i!=j || (i==1 && j==1))
        {
            int next=max(i,j);
            dp[i][next+1]=min(dp[i][next+1],dp[i][j]+a[j][next+1]);
            dp[next+1][j]=min(dp[next+1][j],dp[i][j]+a[i][next+1]);
            if (i==n || j==n) out=min(out,dp[i][j]+a[i][1]+a[j][1]);
        }
    if (out==1e9) cout<<0;
    else cout<<out;
    return 0;
}

