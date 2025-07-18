#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int,int>> matrixs;
int dp[501][501];

int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int r,c;
        cin>>r>>c;
        matrixs.push_back({r,c});
    }

    for(int i=0;i<N;i++) dp[i][i]=0;

    for(int dist=1;dist<N;dist++)
    {
        for(int i=0;i<N-dist;i++)
        {
            int j=i+dist;

            for(int d=0;d<dist;d++)
            {
                int temp=dp[i][i+d]+dp[i+d+1][j];
                temp+=matrixs[i].first*matrixs[i+d+1].first*matrixs[j].second;

                if(dp[i][j]==0 or dp[i][j]>temp) dp[i][j]=temp;
            }
        }
    }

    cout<<dp[0][N-1]<<"\n";

    return 0;
}