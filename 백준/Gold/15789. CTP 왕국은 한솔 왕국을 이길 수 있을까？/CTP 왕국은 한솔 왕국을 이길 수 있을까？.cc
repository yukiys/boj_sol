#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
int C,H,K,ret;
vector<int> parent;
vector<int> Size;

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

    if(Size[a-1]>Size[b-1])
    {
        parent[b]=a;
        Size[a-1]+=Size[b-1];
        Size[b-1]=0;
    }
    else
    {
        parent[a]=b;
        Size[b-1]+=Size[a-1];
        Size[a-1]=0;
    }
}

int main()
{
    cin>>N>>M;

    parent.resize(N+1);
    Size.resize(N);

    for(int i=1;i<=N;i++)
    {
        parent[i]=i;
        Size[i-1]=1;
    }

    for(int i=0;i<M;i++)
    {
        int X,Y;
        cin>>X>>Y;

        Union(X,Y);
    }

    cin>>C>>H>>K;

    ret=Size[Find(C)-1];
    Size[Find(C)-1]=0;
    Size[Find(H)-1]=0;

    sort(Size.rbegin(),Size.rend());
    for(int i=0;i<K;i++) ret+=Size[i];

    cout<<ret<<"\n";

    return 0;
}