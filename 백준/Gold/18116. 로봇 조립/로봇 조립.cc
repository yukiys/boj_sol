#include <iostream>

using namespace std;

int N;
int parent[1000001];
int parts[1000001];

int getParent(int a)
{
    if(parent[a]==a) return a;
    else return parent[a]=getParent(parent[a]);
}

void Union(int a,int b)
{
    a=getParent(a);
    b=getParent(b);
    if(a==b) return;

    if(a<b)
    {
        parent[b]=a;
        parts[a]+=parts[b];
    }
    else
    {
        parent[a]=b;
        parts[b]+=parts[a];
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>N;

    for(int i=1;i<=1000000;i++)
    {
        parent[i]=i;
        parts[i]=1;
    }

    for(int n=0;n<N;n++)
    {
        char op;
        cin>>op;
        if(op=='I')
        {
            int a,b;
            cin>>a>>b;
            Union(a,b);
        }
        else
        {
            int c;
            cin>>c;
            cout<<parts[getParent(c)]<<"\n";
        }
    }

    return 0;
}