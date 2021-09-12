#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long int ll;
//typedef pair<ll,pair<ll,ll> >data;
#define fore(i,a,b) for (ll i=a;i<=b;++i)
#define forw(i,a,b) for (ll i=a;i>=b;i--)
#define fast {ios::sync_with_stdio(false); cin.tie(0); }
#define fi first
#define se second
#define pu push
#define pb push_back
#define fr front
const int tx[4]={-1,1,-1,1};
const int ty[4]={-1,-1,1,1};
const ll oo=1e18;
const ll MOD=1e9+7;
char a[1005],b[1005];
int n,m,k,ans;
int count(int x)
{
    int res=0;
    int j=x;
    fore(i,0,m-1)
    {
        if (j==n) j=0;
        if (b[i]!=a[j]) res++;
        if (res>=ans) return ans;
        j++;
    }
    return res;
}
int main()
{
    fast;
    scanf("%d%d%d",&n,&m,&k);
    scanf("%s",&a);
    ans=m;
    fore(i,1,k)
    {
        scanf("%s",&b);
        fore(i,0,n-1)
            ans=min(ans,count(i));
    }
    printf("%d",ans);
    return 0;
}
