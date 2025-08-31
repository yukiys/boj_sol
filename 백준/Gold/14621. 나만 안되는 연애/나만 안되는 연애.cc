#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,cnt,ret;
char MW[1001];
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

int main()
{
    cin>>N>>M;
    for(int i=1;i<=N;i++)
    {
        cin>>MW[i];
        parent[i]=i;
    }

    for(int i=0;i<M;i++)
    {
        int u,v,d;
        cin>>u>>v>>d;

        V.push_back({d,{u,v}});
    }
    sort(V.begin(),V.end());

    for(int i=0;i<V.size();i++)
    {
        int dist=V[i].first;
        int now=V[i].second.first;
        int next=V[i].second.second;

        if(Find(now)==Find(next) or MW[now]==MW[next]) continue;

        cnt++;
        Union(now,next);
        ret+=dist;

        if(cnt==N-1) break;
    }

    if(cnt==N-1) cout<<ret<<"\n";
    else cout<<-1<<"\n";

    return 0;
}