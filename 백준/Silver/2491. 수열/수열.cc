#include <iostream>

using namespace std;

int main()
{
    int N; cin>>N;
    int A[100000],dp1[100000],dp2[100000];
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
        dp1[i]=1;
        dp2[i]=1;
    }

    for(int i=1;i<N;i++)
        if(A[i-1]<=A[i])
            dp1[i]=dp1[i-1]+1;
    for(int i=1;i<N;i++)
        if(A[i-1]>=A[i])
            dp2[i]=dp2[i-1]+1;

    int M=0;
    for(int i=0;i<N;i++)
        M=max(M,dp1[i]);
    for(int i=0;i<N;i++)
        M=max(M,dp2[i]);

    cout<<M<<"\n";

    return 0;
}