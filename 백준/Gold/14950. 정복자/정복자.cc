#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,t,cnt,ret;
int parent[10001];
vector<pair<int,pair<int,int>>> V;

void init()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>N>>M>>t;

    for(int i=1;i<=N;i++) parent[i]=i;

    for(int i=0;i<M;i++)
    {
        int A,B,C;
        cin>>A>>B>>C;
        V.push_back({C,{A,B}});
    }
}

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

void solve()
{
    sort(V.begin(),V.end());
    
    for(int i=0;i<M;i++)
    {
        int cost=V[i].first;
        int now=V[i].second.first;
        int next=V[i].second.second;

        if(Find(now)==Find(next)) continue;
        cnt++;

        Union(now,next);
        ret+=cost;

        if(cnt==N-1) break;
    }

    int temp=(N-2)*(N-1)*t/2;
    ret+=temp;
}

void printRet()
{
    cout<<ret<<"\n";
}

int main()
{
    init();
    solve();
    printRet();
}