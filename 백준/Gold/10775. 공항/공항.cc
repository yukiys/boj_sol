#include <iostream>

using namespace std;

int G,P,ret;
int parent[100001];

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
    cin>>G>>P;

    for(int i=0;i<=G;i++) parent[i]=i;

    for(int i=0;i<P;i++)
    {
        int g;
        cin>>g;

        int p=Find(g);
        if(p==0) break;
        Union(p,p-1);
        ret++;
    }

    cout<<ret<<"\n";

    return 0;
}