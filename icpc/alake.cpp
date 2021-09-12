#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,pair<ll,ll> >data;
typedef pair<ll, string> super;
#define fore(i,a,b) for (ll i=a;i<=b;i++)
#define forw(i,a,b) for (ll i=a;i>=b;i--)
#define fast {ios::sync_with_stdio(false); cin.tie(0); }
#define fi first
#define se second
#define pu push
#define puf push_front
#define pub push_back
#define pof pop_front
#define pob pop_back
#define fr front
const ll oo=1e18;
const ll MOD=1e9+7;
struct dat
{
    ll pos,w,h;
};
ll n,w[100005],h[100005],ans[100005];
void solve()
{
    cin>>n;
    ll day=oo;
    ll pos=0;
    fore(i,1,n)
    {
        cin>>w[i]>>h[i];
        if (h[i]<day)
        {
            day=h[i];
            pos=i;
        }
    }
    w[0]=w[n+1]=1;
    h[0]=h[n+1]=oo;
    stack<dat> l,r;
    fore(i,0,pos-1)
        l.pu({i,w[i],h[i]});
    forw(i,n+1,pos+1)
        r.pu({i,w[i],h[i]});
    ll time=0;
    ll w1=w[pos];
    ll h1=h[pos];
    while (l.size()>0 && r.size()>0)
    {
        /*cout<<pos<<" "<<w1<<" "<<h1<<endl;
        cout<<"ok "<<l.top().h<<" "<<r.top().h<<endl;*/
        if (l.top().h>h1 && h1<r.top().h)
        {
            ans[pos]=time+w1;

            if (l.top().h<r.top().h)
            {
                time+=(l.top().h-h1)*w1;
                h1=l.top().h;
                w1=l.top().w+w1;
                pos=l.top().pos;
                l.pop();
            }
            else
            {
                time+=(r.top().h-h1)*w1;
                h1=r.top().h;
                w1=r.top().w+w1;
                pos=r.top().pos;
                r.pop();
            }
        }
        else
            if (l.top().h<r.top().h)
            {
                r.pu({pos,w1,h1});
                w1=l.top().w;
                h1=l.top().h;
                pos=l.top().pos;
                l.pop();
            }
            else
            {
                l.pu({pos,w1,h1});
                w1=r.top().w;
                h1=r.top().h;
                pos=r.top().pos;
                r.pop();
            }
        /*cout<<pos<<" "<<w1<<" "<<h1<<endl;
        cout<<l.size()<<" "<<r.size()<<endl;
        cout<<"///"<<endl;*/
    }
    fore(i,1,n)
    cout<<ans[i]<<endl;
}
int main()
{
    fast;
    solve();
    return 0;
}
