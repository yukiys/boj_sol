#include <iostream>

using namespace std;

int N,M;
int parent[1000001];

int getParent(int x)
{
    if(parent[x]==x) return x;
    return parent[x]=getParent(parent[x]);
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

    cin>>N>>M;

    for(int i=1;i<=N;i++) parent[i]=i;

    for(int i=0;i<M;i++)
    {
        int op,a,b;
        cin>>op>>a>>b;

        if(op==0) Union(a,b);
        else
        {
            if(Find(a,b)) cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
        }
    }

    return 0;
}