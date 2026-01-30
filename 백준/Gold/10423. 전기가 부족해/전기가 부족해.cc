#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,K,ret;
int parent[1001];
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
    cin>>N>>M>>K;

    for(int i=0;i<=N;i++)
        parent[i]=i;
    
    for(int i=0;i<K;i++)
    {
        int k;
        cin>>k;
        V.push_back({0,{0,k}});
    }

    for(int i=0;i<M;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        V.push_back({w,{u,v}});
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
        
        Union(now,next);
        ret+=cost;
        cnt++;

        if(cnt==N) break;
    }
}

void printRet()
{
    cout<<ret<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    init();
    Kruskal();
    printRet();
}