#include <iostream>
#include <queue>

using namespace std;

int T,N;
int team[100001];
int degree[100001];

void input()
{
    cin>>N;

    for(int i=1;i<=N;i++) degree[i]=0;
    
    for(int i=1;i<=N;i++)
    {
        cin>>team[i];
        degree[team[i]]++;
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

        int next=team[cur];
        if((--degree[next])==0)
            q.push(next);
    }
}

void printResult()
{
    int cycle=0;
    for(int i=1;i<=N;i++)
        if(degree[i]==0)
            cycle++;

    cout<<cycle<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>T;
    while(T--)
    {
        input();
        solve();
        printResult();
    }

    return 0;
}