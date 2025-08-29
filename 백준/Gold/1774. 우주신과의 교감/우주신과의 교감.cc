#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N,M;
double ret;
int parent[1001];
pair<long,long> stars[1001];
vector<pair<double,pair<int,int>>> v;

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

    cin>>N>>M;

    for(int i=1;i<=N;i++)
    {
        parent[i]=i;
        cin>>stars[i].first>>stars[i].second;
    }

    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;

        Union(a,b);
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
            if(Find(i)==Find(j)) continue;
            
            double dist=(stars[i].first-stars[j].first)*(stars[i].first-stars[j].first);
            dist+=(stars[i].second-stars[j].second)*(stars[i].second-stars[j].second);
            dist=sqrt(dist);

            v.push_back({dist,{i,j}});
        }
    }
    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++)
    {
        double dist=v[i].first;
        int now=v[i].second.first;
        int next=v[i].second.second;

        if(Find(now)==Find(next)) continue;

        Union(now,next);
        ret+=dist;
    }

    cout<<fixed;
    cout.precision(2);
    cout<<ret<<"\n";

    return 0;
}