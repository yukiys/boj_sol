#include <iostream>

#define INF 1e9

using namespace std;

int N,M,K,ret;
int parent[10001];
int cost[10001];
int Min[10001];

int getParent(int a)
{
    if(parent[a]==a) return a;
    else return parent[a]=getParent(parent[a]);
}

void Union(int a,int b)
{
    a=getParent(a);
    b=getParent(b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}

bool Find(int a,int b)
{
    a=getParent(a);
    b=getParent(b);
    if(a==b) return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>N>>M>>K;

    for(int i=1;i<=N;i++)
    {
        cin>>cost[i];
        parent[i]=i;
        Min[i]=INF;
    }

    for(int i=0;i<M;i++)
    {
        int v,w;
        cin>>v>>w;
        Union(v,w);
    }

    for(int i=1;i<=N;i++) Min[getParent(i)]=min(Min[getParent(i)],cost[i]);

    for(int i=1;i<=N;i++)
        if(Min[i]!=INF)
            ret+=Min[i];

    if(ret<=K) cout<<ret<<"\n";
    else cout<<"Oh no"<<"\n";

    return 0;
}