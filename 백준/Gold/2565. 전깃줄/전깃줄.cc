#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N; cin>>N;

    vector<pair<int,int>> v;
    vector<int> dp(N,1);

    for(int i=0;i<N;i++)
    {
        int a,b; cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());

    for(int i=0;i<N;i++)
        for(int j=0;j<i;j++)
            if(v[j].second<v[i].second)
                dp[i]=max(dp[i],dp[j]+1);
    
    int M=0;
    for(int i=0;i<N;i++) M=max(M,dp[i]);
    
    cout<<N-M<<"\n";

    return 0;
}