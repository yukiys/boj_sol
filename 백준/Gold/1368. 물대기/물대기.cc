#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,mst;
int parent[301];
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

void init()
{
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        parent[i]=i;

        int W;
        cin>>W;
        V.push_back({W,{0,i}});
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            int P;
            cin>>P;
            if(i<j) V.push_back({P,{i,j}});
        }
    }
    sort(V.begin(),V.end());
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

        if(cnt==N) break;
    }
}

void printRet()
{
    cout<<mst<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    init();
    Kruskal();
    printRet();
}