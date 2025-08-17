#include <iostream>

using namespace std;

int N,M;
int parent[201];
int plan[1001];

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

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            int temp;
            cin>>temp;
            if(temp) Union(i,j);
        }
    }

    for(int i=1;i<=M;i++) cin>>plan[i];
    
    for(int i=2;i<=M;i++)
    {
        if(Find(plan[i-1],plan[i])) continue;
        cout<<"NO"<<"\n";
        return 0;
    }
    cout<<"YES"<<"\n";

    return 0;
}