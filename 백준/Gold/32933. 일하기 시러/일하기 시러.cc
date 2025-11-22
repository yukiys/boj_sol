#include <iostream>
#include <vector>

using namespace std;

int N,M,K;
vector<pair<int,pair<int,int>>> ABC;
int dp[51];

void input()
{
    cin>>N>>M>>K;
    for(int i=0;i<K;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        ABC.push_back({a,{b,c}});
    }
}

void solve()
{
    for(int t=0;t<=M;t++)
    {
        for(int i=0;i<ABC.size();i++)
        {
            int a=ABC[i].first;
            int b=ABC[i].second.first;
            int c=ABC[i].second.second;

            int cur=t+a;
            if(cur>M) continue;
            int gain=dp[t]+c;
            while(cur<=M)
            {
                dp[cur]=max(dp[cur],gain);
                cur+=b;
                gain+=c;
            }
        }
    }
}

void printResult()
{
    cout<<N*dp[M]<<"\n";
}

int main()
{
    input();
    solve();
    printResult();

    return 0;
}