#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int n,m,dp[1005],a[15][1005];
vector <int> check[1005];
bool test(int x, int y)
{
    for (int i=0;i<m;i++)
        if (check[x][i]<check[y][i]) return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            check[a[i][j]].pb(j);
        }
    int out=0;
    //cout<<test
    for (int i=1;i<=n;i++)
    {
        int x=a[1][i];
        dp[x]=1;
        for (int j=1;j<i;j++)
        {
            int y=a[1][j];
            if (test(x,y))
                dp[x]=max(dp[x],dp[y]+1);
        }
        //cout<<x<<" "<<dp[x]<<endl;
        out=max(out,dp[x]);
    }
    cout<<out;
    return 0;
}
