#include <iostream>
#include <vector>

using namespace std;

int N;
long long T;
int pick[101];
int visited[101];
vector<int> order;

int main()
{
    cin>>N>>T;
    for(int n=1;n<=N;n++)
    {
        cin>>pick[n];
        visited[n]=-1;
    }

    int cur=1,step=0;
    while(visited[cur]==-1)
    {
        visited[cur]=step++;
        order.push_back(cur);
        cur=pick[cur];
    }

    int cStart=visited[cur];
    int cLength=step-cStart;

    if(T<cStart) cout<<order[T]<<"\n";
    else
    {
        T=(T-cStart)%cLength;
        cout<<order[cStart+T]<<"\n";
    }

    return 0;
}