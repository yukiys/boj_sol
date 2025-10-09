#include <iostream>

using namespace std;

int N,M;
int A[100],B[100],ret[100];
int aIdx,bIdx,retIdx;

void input()
{
    cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];

    cin>>M;
    for(int i=0;i<M;i++) cin>>B[i];
}

void solve()
{
    while(aIdx<N and bIdx<M)
    {
        int a=aIdx;
        int b=bIdx;
        int Max=0;

        for(int i=aIdx;i<N;i++)
        {
            for(int j=bIdx;j<M;j++)
            {
                if(A[i]==B[j] and A[i]>Max)
                {
                    Max=A[i];
                    a=i;
                    b=j;
                }
            }
        }

        if(Max==0) return;

        ret[retIdx++]=Max;
        aIdx=a+1;
        bIdx=b+1;
    }
}

void printResult()
{
    cout<<retIdx<<"\n";
    for(int i=0;i<retIdx;i++) cout<<ret[i]<<" ";
    cout<<"\n";
}

int main()
{
    input();
    solve();
    printResult();

    return 0;
}