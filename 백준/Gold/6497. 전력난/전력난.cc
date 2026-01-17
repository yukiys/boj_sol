#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m,n,total,mst;
int parent[200000];
vector<pair<int,pair<int,int>>> V;

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

bool init()
{
    cin>>m>>n;
    if(m==0 and n==0) return false;
    total=0;
    mst=0;

    for(int i=0;i<m;i++) parent[i]=i;

    V.clear();
    for(int i=0;i<n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        total+=z;
        V.push_back({z,{x,y}});
    }
    sort(V.begin(),V.end());

    return true;
}

void Kruskal()
{
    int cnt=0;
    for(int i=0;i<V.size();i++)
    {
        int cost=V[i].first;
        int now=V[i].second.first;
        int next=V[i].second.second;

        if(Find(now)==Find(next)) continue;
        cnt++;
        
        Union(now,next);
        mst+=cost;

        if(cnt==m-1) return;
    }
}

void printRet()
{
    cout<<total-mst<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    while(init())
    {
        Kruskal();
        printRet();
    }
}