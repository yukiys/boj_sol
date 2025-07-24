#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N,K;
vector<int> Time(100001,1e9);
vector<int> Parent(100001,-1);

void bfs(int start)
{
    queue<int> q;
    Time[start]=0;
    Parent[start]=start;
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
                Parent[next]=cur;
                q.push(next);
            }
        }
        if(cur!=100000)
        {
            int next=cur+1;
            if(Time[next]>Time[cur]+1)
            {
                Time[next]=Time[cur]+1;
                Parent[next]=cur;
                q.push(next);
            }
        }
        if(2*cur<=100000)
        {
            int next=2*cur;
            if(Time[next]>Time[cur]+1)
            {
                Time[next]=Time[cur]+1;
                Parent[next]=cur;
                q.push(next);
            }
        }
    }
}

int main()
{
    cin>>N>>K;

    bfs(N);

    vector<int> path;
    for(int cur=K;cur!=N;cur=Parent[cur]) path.push_back(cur);
    path.push_back(N);
    
    reverse(path.begin(),path.end());

    cout<<Time[K]<<"\n";
    for(int i=0;i<path.size();i++) cout<<path[i]<<" ";
    cout<<"\n";

    return 0;
}