#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,K;

vector<pair<int,int>> v(100001,{1000000000,0});

void bfs(int start)
{
    queue<int> q;
    v[start].first=0;
    v[start].second=1;
    q.push(start);

    while(!q.empty())
    {
        int cur=q.front();
        q.pop();

        if(cur!=0)
        {
            int b=cur-1;
            if(v[b].first>v[cur].first+1)
            {
                q.push(b);
                v[b].first=v[cur].first+1;
                v[b].second=v[cur].second;
            }
            else if(v[b].first==v[cur].first+1)
            {
                v[b].second+=v[cur].second;
            }
        }
        if(cur!=100000)
        {
            int b=cur+1;
            if(v[b].first>v[cur].first+1)
            {
                q.push(b);
                v[b].first=v[cur].first+1;
                v[b].second=v[cur].second;
            }
            else if(v[b].first==v[cur].first+1)
            {
                v[b].second+=v[cur].second;
            }
        }
        if(cur<=50000)
        {
            int b=2*cur;
            if(v[b].first>v[cur].first+1)
            {
                q.push(b);
                v[b].first=v[cur].first+1;
                v[b].second=v[cur].second;
            }
            else if(v[b].first==v[cur].first+1)
            {
                v[b].second+=v[cur].second;
            }
        }
    }
}

int main()
{
    cin>>N>>K;

    bfs(N);

    cout<<v[K].first<<"\n"<<v[K].second<<"\n";

    return 0;
}