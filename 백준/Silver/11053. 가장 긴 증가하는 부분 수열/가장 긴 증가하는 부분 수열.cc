#include <iostream>

using namespace std;

int main()
{
    int N; cin>>N;

    int A[1001],dp[1001];
    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
        dp[i]=1;
    }
    
    for(int i=1;i<=N;i++)
        for(int j=1;j<=i;j++)
            if(A[j]<A[i])
                dp[i]=max(dp[i],dp[j]+1);

    int M=0;
    for(int i=1;i<=N;i++)
        if(M<dp[i])
            M=dp[i];
    
    cout<<M<<"\n";

    return 0;
}