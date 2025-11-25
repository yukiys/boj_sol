#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

int X,Y,D,N;
vector<pair<int,int>> ab;
bitset<10000001> dp;
int totalSum,bestReward,bestCost;

void input()
{
    cin>>X>>Y>>D;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int a,b;
        cin>>a>>b;
        ab.push_back({a,b});
    }
}

void solve()
{
    vector<int> price;
    
    for(int i=0;i<ab.size();i++)
    {
        int a=ab[i].first;
        int b=ab[i].second;
        for(int j=0;j<a;j++)
        {
            price.push_back(b);
            totalSum+=b;
        }
    }

    dp[0]=1;
    for(int w:price)
        dp|=(dp<<w);

    for(int s=0;s<=totalSum;s++)
    {
        if(!dp[s]) continue;

        int reward=(s/X)*Y;
        if(reward>D) reward=D;

        if(reward>bestReward)
        {
            bestReward=reward;
            bestCost=s;
        }
    }
}

void printResult()
{
    if(bestReward==0) cout<<0<<"\n";
    else cout<<bestCost<<"\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    input();
    solve();
    printResult();
    
    return 0;
}