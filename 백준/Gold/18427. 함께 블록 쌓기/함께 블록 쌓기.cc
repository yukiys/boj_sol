#include <iostream>
#include <vector>
#include <sstream>

#define MOD 10007

using namespace std;

int N,M,H;
vector<int> blocks[51];
int dp[51][1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M>>H;
    cin.ignore();

    for(int i=1;i<=N;i++)
    {
        string str;
        getline(cin,str);

        int num;
        stringstream ss(str);
        while(ss>>num) blocks[i].push_back(num);
    }

    for(int i=0;i<=N;i++) dp[i][0]=1;

    for(int n=1;n<=N;n++)
    {
        for(int h=1;h<=H;h++)
        {
            dp[n][h]=(dp[n][h]+dp[n-1][h])%MOD;

            for(int i=0;i<blocks[n].size();i++)
            {
                int temp=blocks[n][i];
                if(h>=temp) dp[n][h]=(dp[n][h]+dp[n-1][h-temp])%MOD;
            }
        }
    }

    cout<<dp[N][H]<<"\n";

    return 0;
}