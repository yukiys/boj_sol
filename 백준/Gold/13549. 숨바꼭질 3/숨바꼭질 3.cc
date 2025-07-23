#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N,K;
vector<int> Time(100001,1e9);

void bfs(int start)
{
    queue<int> q;
    Time[start]=0;
    q.push(start);

    while(!q.empty())
    {
        int cur=q.front();
        q.pop();

        if(cur!=0)
        {
            int next=cur-1;
            if(Time[next]>Time[cur]+1)
            {
                Time[next]=Time[cur]+1;
                q.push(next);
            }
        }
        if(cur!=100000)
        {
            int next=cur+1;
            if(Time[next]>Time[cur]+1)
            {
                Time[next]=Time[cur]+1;
                q.push(next);
            }
        }
        if(2*cur<=100000)
        {
            int next=2*cur;
            if(Time[next]>Time[cur])
            {
                Time[next]=Time[cur];
                q.push(next);
            }
        }
    }
}

int main()
{
    cin>>N>>K;

    bfs(N);

    cout<<Time[K]<<"\n";

    return 0;
}