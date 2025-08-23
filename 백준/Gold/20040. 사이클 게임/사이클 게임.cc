#include <iostream>

using namespace std;

int N,M;
int parent[500000];
int Rank[500000];

int Find(int a)
{
    if(parent[a]==a) return a;
    return parent[a]=Find(parent[a]);
}

bool Union(int a,int b)
{
    a=Find(a);
    b=Find(b);
    if(a==b) return true;

    if(Rank[a]<Rank[b])
    {
        parent[a]=b;
        Rank[b]+=Rank[a];
    }
    else
    {
        parent[b]=a;
        Rank[a]+=Rank[b];
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>N>>M;

    for(int i=0;i<N;i++)
    {
        parent[i]=i;
        Rank[i]=1;
    }

    for(int i=1;i<=M;i++)
    {
        int a,b;
        cin>>a>>b;
        if(Union(a,b))
        {
            cout<<i<<"\n";
            break;
        }
        if(i==M) cout<<0<<"\n";
    }

    return 0;
}