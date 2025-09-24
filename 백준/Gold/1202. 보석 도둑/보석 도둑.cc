#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N,K,idx;
long long ret;
pair<int,int> MV[300001];
int C[300001];

void input()
{
    cin>>N>>K;

    for(int i=0;i<N;i++)
    {
        int m,v;
        cin>>m>>v;
        MV[i]={m,v};
    }
    sort(MV,MV+N);
    
    for(int i=0;i<K;i++) cin>>C[i];
    sort(C,C+K);
}

void solve()
{
    priority_queue<int> pq;
    for(int i=0;i<K;i++)
    {
        int c=C[i];
        
        while(idx<N and MV[idx].first<=c) pq.push(MV[idx++].second);

        if(!pq.empty())
        {
            ret+=pq.top();
            pq.pop();
        }
        else continue;
    }
}

void printResult()
{
    cout<<ret<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    input();
    solve();
    printResult();

    return 0;
}