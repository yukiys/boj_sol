#include <iostream>
#include <cmath>

#define ll long long
const ll INF=4e18;

using namespace std;

pair<ll,ll> p[8];
ll dist[8][8];
ll xs,ys,xe,ye,x,y;

ll manDist(pair<ll,ll> p1,pair<ll,ll> p2)
{
    return abs(p1.first-p2.first)+abs(p1.second-p2.second);
}

void init()
{
    cin>>xs>>ys>>xe>>ye;
    p[0]={xs,ys};
    p[1]={xe,ye};

    for(int i=0;i<3;i++)
    {
        cin>>x>>y;
        p[2+2*i]={x,y};
        cin>>x>>y;
        p[3+2*i]={x,y};
    }

    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if(i!=j)
                dist[i][j]=INF;
                
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            dist[i][j]=min(dist[i][j],manDist(p[i],p[j]));

    for(int i=0;i<3;i++)
    {
        int a=2+2*i;
        int b=3+2*i;
        dist[a][b]=dist[b][a]=min(dist[a][b],10ll);
    }
}

void floyd()
{
    for(int k=0;k<8;k++)
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}

void printRet()
{
    cout<<dist[0][1]<<"\n";
}

int main()
{
    init();
    floyd();
    printRet();
}