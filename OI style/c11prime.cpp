#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef unsigned long long int ll;
vector <ll> prime;
bool notprime[2000000];
ll n;
void sieve()
{
    for (ll i=2;i<=1e6;i++)
    if (!notprime[i])
    {
        for (ll j=i*i;j<=1e6;j+=i)
            notprime[j]=true;
        prime.pb(i);
    }
}
bool check(ll x)
{
    for (ll i=0;i<prime.size() && x>1;i++)
    if (x%prime[i]==0) return false;
    return x!=1;
}
ll tich(ll n, ll x)
{
    ll out=n;
    for (int i=2;i<=x;i++)
        out*=n;
    return out;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    sieve();
    for (int i=64;i>=2;i--)
    {
    ll res1=round(pow(n,1.0/i));
    ll res2=ceil(pow(n,1.0/i));
    ll p1=tich(res1,i);
    ll p2=tich(res2,i);
    if (p1==n || p2==n)
    {
        ll res=res1;
        if (p2==n) res=res2;
        if ((res<1e6 && !notprime[res]) || check(res))
        {
            cout<<res<<" "<<i;
            return 0;
        }
    }
    }
    cout<<0;
    return 0;
}
