#include <iostream>
#include <vector>

using namespace std;

int N,M;
vector<pair<int,int>> target;
long long ret;

int main()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        int a,b;
        cin>>a>>b;
        target.push_back({a,b});
    }

    int x=0,y=0;
    while(M--)
    {
        int bestIdx=-1;
        int nx,ny;
        int best=0;
        for(int i=0;i<target.size();i++)
        {
            int dist=(target[i].first-x)*(target[i].first-x)+(target[i].second-y)*(target[i].second-y);
            if(best<dist)
            {
                best=dist;
                bestIdx=i;
                nx=target[i].first;
                ny=target[i].second;
            }
        }

        ret+=best;
        x=nx;
        y=ny;
        cin>>target[bestIdx].first>>target[bestIdx].second;
    }

    cout<<ret<<"\n";

    return 0;
}