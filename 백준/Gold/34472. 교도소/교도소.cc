#include <iostream>

using namespace std;

int N,S,E;
long long sum;
long long A[500001],mean,ret;

void input()
{
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
        mean+=A[i];
    }
    mean/=N;
    for(int i=1;i<=N;i++) A[i]-=mean;
}

void solve()
{
    E=N;
    while(S!=E)
    {
        if(S==N+1) S=1;
        if(sum<0)
        {
            E=S-1;
            sum=0;
            ret=0;
        }

        sum+=A[S++];
        ret+=sum;
    }
}

void printResult()
{
    cout<<ret<<"\n";
}

int main()
{
    input();
    solve();
    printResult();

    return 0;
}