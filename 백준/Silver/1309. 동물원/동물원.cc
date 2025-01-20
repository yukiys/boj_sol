#include <iostream>

using namespace std;

#define MOD 9901

int main()
{
    int N; cin>>N;

    int A[100001],B[100001];
    A[1]=2;
    B[1]=1;
    for(int i=2;i<=N;i++)
    {
        A[i]=(A[i-1]+B[i-1]*2)%MOD;
        B[i]=(A[i-1]+B[i-1])%MOD;
    }
    cout<<(A[N]+B[N])%MOD<<"\n";

    return 0;
}