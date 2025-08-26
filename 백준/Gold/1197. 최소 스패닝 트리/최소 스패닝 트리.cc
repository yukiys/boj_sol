#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V,E,ret,cnt;
int parent[10001];
vector<pair<int,pair<int,int>>> v;

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
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>V>>E;

    for(int i=1;i<=V;i++) parent[i]=i;

    for(int i=0;i<E;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back({c,{a,b}});
    }

    sort(v.begin(),v.end());

    for(int i=0;i<E;i++)
    {
        int cost=v[i].first;
        int now=v[i].second.first;
        int next=v[i].second.second;

        if(Find(now)==Find(next)) continue;
        cnt++;

        Union(now,next);
        ret+=cost;

        if(cnt==V-1) break;
    }

    cout<<ret<<"\n";

    return 0;
}