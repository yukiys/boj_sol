#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M,idx=1;
vector<int> edges[1001];
int degree[1001],ret[1001];

void input()
{
    cin>>N>>M;
    
    for(int i=0;i<M;i++)
    {
        int num;
        cin>>num;

        int A,B;
        cin>>A;
        for(int j=1;j<num;j++)
        {
            cin>>B;
            edges[A].push_back(B);
            degree[B]++;
            A=B;
        }
    }
}

void solve()
{
    queue<int> q;

    for(int i=1;i<=N;i++)
        if(degree[i]==0)
            q.push(i);

    while(!q.empty())
    {
        int cur=q.front();
        q.pop();

        ret[idx++]=cur;

        for(int next:edges[cur])
            if((--degree[next])==0)
                q.push(next);
    }
}

void printResult()
{
    if(idx!=N+1)
    {
        cout<<0<<"\n";
        return;
    }
    for(int i=1;i<=N;i++) cout<<ret[i]<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    input();
    solve();
    printResult();

    return 0;
}