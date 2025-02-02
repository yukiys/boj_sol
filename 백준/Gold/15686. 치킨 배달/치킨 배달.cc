#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N,M,ans=1000000000;
int map[51][51];
bool check[13];
vector<pair<int,int>> house;
vector<pair<int,int>> chicken;

int calc()
{
    int m=0;
    for(int i=0;i<house.size();i++)
    {
        int y=house[i].first;
        int x=house[i].second;

        int temp=1000000000;
        for(int j=0;j<chicken.size();j++)
        {
            if(check[j])
            {
                int cy=chicken[j].first;
                int cx=chicken[j].second;

                temp=min(temp,abs(y-cy)+abs(x-cx));
            }
        }
        m+=temp;
    }
    return m;
}

void dfs(int idx,int cnt)
{
    if(cnt==M)
    {
        ans=min(ans,calc());
        return;
    }

    for(int i=idx;i<chicken.size();i++)
    {
        if(!check[i])
        {
            check[i]=true;
            dfs(i+1,cnt+1);
            check[i]=false;
        }
    }
}

int main()
{
    cin>>N>>M;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin>>map[i][j];
            if(map[i][j]==1) house.push_back({i,j});
            else if(map[i][j]==2) chicken.push_back({i,j});
        }
    }

    dfs(0,0);

    cout<<ans<<"\n";

    return 0;
}