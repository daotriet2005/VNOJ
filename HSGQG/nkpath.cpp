#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD=1e9;
ll dp[105][105],n,m,a[105][105];
bool check(int a, int b)
{
    if (a<b) swap(a,b);
    while (b!=0)
    {
        int x=a%b;
        a=b;
        b=x;
    }
    return a!=1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m>>n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    for (int i=1;i<=m;i++) dp[i][n]=1;
    for (int i=m;i>=1;i--)
        for (int j=n;j>=1;j--)
            for (int ii=1;ii<=i;ii++)
                for (int jj=1;jj<=j;jj++)
                    if ((ii!=i || jj!=j) && jj!=n)
                        if (check(a[ii][jj],a[i][j]))
                            dp[ii][jj]+=(dp[i][j]%MOD);
    ll out=0;
    for (int i=1;i<=m;i++)
        out+=dp[i][1]%MOD;
    cout<<out%MOD;
    return 0;
}
