#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int T;
int Start,End;
bool visited[10001];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>T;
    while(T--)
    {
        vector<string> ret(10001);
        memset(visited,0,sizeof(visited));

        cin>>Start>>End;

        queue<int> q;
        q.push(Start);
        visited[Start]=true;

        while(!q.empty())
        {
            int x=q.front();
            q.pop();

            if(x==End)
            {
                cout<<ret[x]<<"\n";
                break;
            }
            
            int nx=(2*x)%10000;
            if(!visited[nx])
            {
                ret[nx]=ret[x]+"D";
                visited[nx]=true;
                q.push(nx);
            }

            nx=(x==0)?9999:x-1;
            if(!visited[nx])
            {
                ret[nx]=ret[x]+"S";
                visited[nx]=true;
                q.push(nx);
            }

            nx=(x%1000)*10+(x/1000);
            if(!visited[nx])
            {
                ret[nx]=ret[x]+"L";
                visited[nx]=true;
                q.push(nx);
            }

            nx=(x/10)+(x%10)*1000;
            if(!visited[nx])
            {
                ret[nx]=ret[x]+"R";
                visited[nx]=true;
                q.push(nx);
            }
        }
    }

    return 0;
}