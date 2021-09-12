#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef pair<int, pair<int, int> > data;
//typedef pair<int, int> data1;
int dp[405][40005];
data a[405];
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.inp","r",stdin);
    cin>>n;
    int super=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].se.fi>>a[i].fi>>a[i].se.se;
        super=max(super,a[i].fi);
    }
    // val - limit(high) - limit(numbers)
    sort(a+1,a+n+1);
    a[0].fi=super;
    for (int i=0;i<=n;i++)
        for (int j=0;j<=super;j++) dp[i][j]=-1;
    dp[1][0]=0;
    for (int i=1;i<=n;i++)
    {
        int limit=a[i].fi;
        int val=a[i].se.fi;
        int num=a[i].se.se;
        for (int j=0;j<=super;j++)
        {
            if (dp[i-1][j]!=-1) {
                dp[i][j]=0;
                //cout<<dp[i-1][j]<<" ";
            }
            if (j>=val && j<=limit)
            {
                if (dp[i][j-val]!=-1 && dp[i][j-val]+1<=num ) {
                    dp[i][j]=dp[i][j-val]+1;
                    //cout<<dp[i][j-val]<<" ";
                }
                if (dp[i-1][j-val]!=-1 && num>=1 && j-val<=a[i-1].fi) {
                    dp[i][j]=1;
                    //cout<<dp[i-1][j-val]<<" ";
                }
            }
            //cout<<j<<" "<<dp[i][j]<<endl;
        }
        //cout<<"/////////////"<<endl;
    }
    int out=0;
    for (int i=0;i<=a[n].fi;i++)
    if (dp[n][i]!=-1) out=max(out,i);
    cout<<out;
    return 0;
}
