#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long mst;
pair<long long,int> X[100000],Y[100000],Z[100000];
int parent[100001];
vector<pair<long long,pair<int,int>>> V;

int Find(int a)
{
    if(parent[a]==a) return a;
    return parent[a]=Find(parent[a]);
}

void Union(int a,int b)
{
    a=Find(a);
    b=Find(b);
    if(a==b) return;

    if(a<b) parent[b]=a;
    else parent[a]=b;
}

void getDist()
{
    for(int i=0;i<N-1;i++)
    {
        long long dist;

        dist=abs(X[i].first-X[i+1].first);
        V.push_back({dist,{X[i].second,X[i+1].second}});
        
        dist=abs(Y[i].first-Y[i+1].first);
        V.push_back({dist,{Y[i].second,Y[i+1].second}});
        
        dist=abs(Z[i].first-Z[i+1].first);
        V.push_back({dist,{Z[i].second,Z[i+1].second}});
    }
    sort(V.begin(),V.end());
}

void Kruskal()
{
    int cnt=0;
    for(int i=0;i<V.size();i++)
    {
        long long cost=V[i].first;
        int now=V[i].second.first;
        int next=V[i].second.second;
        if(Find(now)==Find(next)) continue;

        cnt++;
        Union(now,next);
        mst+=cost;

        if(cnt==N-1) break;
    }
}

void init()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        long long x,y,z;
        cin>>x>>y>>z;
        X[i]={x,i+1};
        Y[i]={y,i+1};
        Z[i]={z,i+1};
    }
    
    for(int i=1;i<=N;i++)
        parent[i]=i;
}

void solve()
{
    sort(X,X+N);
    sort(Y,Y+N);
    sort(Z,Z+N);

    getDist();

    Kruskal();
}

void printRet()
{
    cout<<mst<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    init();
    solve();
    printRet();
}