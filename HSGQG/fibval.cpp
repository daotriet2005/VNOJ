#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,pair<int,int> > data;
#define fore(i,a,b) for (ll i=a;i<=b;++i)
#define forw(i,a,b) for (ll i=a;i>=b;i--)
#define fast {ios::sync_with_stdio(false); cin.tie(0); }
#define fi first
#define se second
#define pu push
#define pb push_back
#define fr front
const int tx[5]={0,-1,0,1,0};
const int ty[5]={0,0,1,0,-1};
const ll oo=1e18;
const ll MOD=1e9+7;
ll u,v,k;
ll dp[105];
ll count()
{
    cin>>u>>v;
    ll res=v-u+1;
    if (res>=32) return (res/16)*16;
    else
        fore(i,u,v-1)
            if (dp[(i+1)%16]==dp[(i+2)%16])
            return 2;
    return -1;

}
int main()
{
    fast;
    cin>>k;
    dp[1]=1;
    dp[2]=1;
    fore(i,3,100) dp[i]=(dp[i-1]+dp[i-2])%7;
    while (k--) cout<<count()<<endl;
    return 0;
}
