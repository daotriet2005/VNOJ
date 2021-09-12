#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll sum[12][40000],a[10005],n,k;
const ll MOD=1e9;
ll find(int x,int id, int l, int r, int u, int v)
{
    if (u<=l && r<=v) return sum[x][id];
    if (r<u || v<l) return 0;
    int mid=(l+r)/2;
    return (find(x,id*2,l,mid,u,v)+find(x,id*2+1,mid+1,r,u,v))%MOD;
}
void update(int x, int id, int l, int r, int pos, int val)
{
    if (l==r && r==pos)
    {
        sum[x][id]+=val%MOD;
        //cout<<x<<" "<<pos<<" "<<val<<endl;
        return;
    }
    if (pos<l || r<pos) return;
    int mid=(l+r)/2;
    update(x,id*2,l,mid,pos,val);
    update(x,id*2+1,mid+1,r,pos,val);
    sum[x][id]=(sum[x][id*2]+sum[x][id*2+1])%MOD;
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    ll out=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=k-1;j>=1;j--)
        {
            ll res=find(j,1,1,n,a[i],n);
            if (j==k-1) out+=res;
            update(j+1,1,1,n,a[i],res);
        }
        if (k==1) out+=1;
        update(1,1,1,n,a[i],1);
    }
    cout<<out%MOD;
    return 0;
}
