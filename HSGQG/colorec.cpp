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
ll a[500][500],dp[500][500],ans,n;
void solve(int x, int y1, int y2)
{
    if (a[x][y1]==a[x][y2]) return;
    int cnt=0;
    int save[5];
    save[1]=save[2]=0;
    int z1=min(a[x][y1],a[x][y2]);
    int z2=max(a[x][y1],a[x][y2]);
    dp[z1][z2]++;
    fore(i,1,4)
        if (i!=a[x][y1] && i!=a[x][y2])
        {
            cnt++;
            save[cnt]=i;
        }
    int v1=save[1];
    int v2=save[2];
    if (v1==0 || v2==0) return;
    //if (dp[v1][v2]>0) cout<<x<<" "<<y1<<" "<<y2<<" "<<a[x][y1]<<" "<<a[x][y2]<<endl;
    ans+=dp[v1][v2];
    return;
}
int main()
{
    fast;
    cin>>n;
    fore(i,1,n)
    {
        int x,y,z;
        cin>>x>>y>>z;
        a[x+200][y+200]=z;
    }
    fore(y1,-199,200)
        fore(y2,-200,y1-1)
        {
            fore(i,1,4)
                fore(j,1,4) dp[i][j]=0;
            fore(x,-200,200)
            {
                if (a[x+200][y1+200] && a[x+200][y2+200])
                    solve(x+200,y1+200,y2+200);
            }
        }
    cout<<ans;
    return 0;
}
