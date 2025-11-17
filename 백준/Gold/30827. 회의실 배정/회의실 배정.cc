#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,K,ret;
vector<pair<int,int>> Times;
int roomEnd[3];

void input()
{
    cin>>N>>K;
    for(int i=0;i<N;i++)
    {
        int s,e;
        cin>>s>>e;
        Times.push_back({e,s});
    }
}

void solve()
{
    sort(Times.begin(),Times.end());

    for(int i=0;i<N;i++)
    {
        int e=Times[i].first;
        int s=Times[i].second;

        int bestRoom=-1;
        int bestEnd=-1;

        for(int j=0;j<K;j++)
        {
            if(roomEnd[j]<s)
            {
                if(bestEnd<roomEnd[j])
                {
                    bestEnd=roomEnd[j];
                    bestRoom=j;
                }
            }
        }
        if(bestRoom==-1) continue;

        roomEnd[bestRoom]=e;
        ret++;
    }
}

void printResult()
{
    cout<<ret<<"\n";
}

int main()
{
    input();
    solve();
    printResult();
}