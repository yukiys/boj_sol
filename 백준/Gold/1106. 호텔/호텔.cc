#include <iostream>
#include <vector>

using namespace std;

int C,N;
vector<pair<int,int>> cities;
vector<int> dp(100001);

int main()
{
    cin>>C>>N;
    
    for(int i=0;i<N;i++)
    {
        int cost,num;
        cin>>cost>>num;
        cities.push_back({cost,num});
    }

    for(int i=0;i<N;i++)
        for(int j=1;j<=100000;j++)
            if(j>=cities[i].first)
                dp[j]=max(dp[j],dp[j-cities[i].first]+cities[i].second);
    
    for(int i=1;i<=100000;i++)
    {
        if(dp[i]>=C)
        {
            cout<<i<<"\n";
            break;
        }
    }

    return 0;
}