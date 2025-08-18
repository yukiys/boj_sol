#include <iostream>
#include <vector>

using namespace std;

int N,M,num,ret;
vector<int> parent;
vector<int> parties[50];

int getParent(int x)
{
    if(parent[x]==x) return x;
    else return parent[x]=getParent(parent[x]);
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
    return a==b;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>N>>M;

    parent.resize(N+1);
    for(int i=1;i<=N;i++) parent[i]=i;

    cin>>num;
    for(int i=1;i<=num;i++)
    {
        int truth;
        cin>>truth;
        Union(0,truth);
    }

    for(int i=0;i<M;i++)
    {
        int T; cin>>T;
        parties[i].resize(T);

        for(int t=0;t<T;t++) cin>>parties[i][t];
        
        for(int t=1;t<T;t++) Union(parties[i][t-1],parties[i][t]);
    }

    for(int i=0;i<M;i++)
    {
        bool b=true;
        for(int j=0;j<parties[i].size();i++)
        {
            if(Find(parties[i][j],0))
            {
                b=false;
                break;
            }
            if(b) ret++;
        }
    }

    cout<<ret<<"\n";

    return 0;
}