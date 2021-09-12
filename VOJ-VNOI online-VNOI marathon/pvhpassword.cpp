#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll val;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    cin>>val;
    ll out=0;
    ll res=0;
    for (int i=0;i<s.length();i++)
    {
    if ((s[i]-'a')+val>=26)
        res=(s[i]-'a')+val-26;
    else res=(s[i]-'a')+val;
    out+=res;
    }
    cout<<out;
    return 0;
}
