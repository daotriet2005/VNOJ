#include <bits/stdc++.h>
using namespace std;
const int tx[4]={0,0,1,-1};
const int ty[4]={1,-1,0,0};
typedef pair<int, int> super;
typedef long long int ll;
#define pu push
bool kt[1005][1005];
int a[1005][1005],n,m,rx,ry;
void bfs(int x,int y)
{
    queue<super> p;
    p.pu({x,y});
    kt[x][y]=true;
    ll count1=0;
    while (!p.empty())
    {
    queue <super> p1;
    while (!p.empty())
    {
        x=p.front().first;
        y=p.front().second;
        p.pop();
        for (int i=0;i<4;i++)
        {
            rx=x+tx[i];
            ry=y+ty[i];
            if (!kt[rx][ry] && a[rx][ry]!=0)
                if (a[rx][ry]==a[x][y])
                {
                    kt[rx][ry]=true;
                    p.pu({rx,ry});
                }
                else
                {
                    kt[rx][ry]=true;
                    p1.pu({rx,ry});
                }
        }
    }
    count1++;
    p=p1;
    }
    cout<<count1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("animal.inp","r",stdin);
    //freopen("animal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            char x;
            cin>>x;
            if (x=='T') a[i][j]=1;
            if (x=='B') a[i][j]=2;
        }
    bfs(1,1);
    return 0;
}
