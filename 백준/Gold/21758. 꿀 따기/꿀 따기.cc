#include <iostream>

using namespace std;

int N;
int honey[100000];
long long lSum[100000],rSum[100000],ret;

void input()
{
    cin>>N;
    for(int i=0;i<N;i++) cin>>honey[i];
}

void solve()
{
    lSum[0]=honey[0];
    for(int i=1;i<N;i++)
        lSum[i]=lSum[i-1]+honey[i];

    rSum[N-1]=honey[N-1];
    for(int i=N-2;i>=0;i--)
        rSum[i]=rSum[i+1]+honey[i];

    for(int i=1;i<N-1;i++)
    {
        long long case1=lSum[N-1]-lSum[0]-honey[i];
        case1+=(lSum[N-1]-lSum[i]);
        ret=max(ret,case1);
    }

    for(int i=N-2;i>=0;i--)
    {
        long long case2=rSum[0]-rSum[N-1]-honey[i];
        case2+=(rSum[0]-rSum[i]);
        ret=max(ret,case2);
    }
    
    for(int i=1;i<N-1;i++)
    {
        long long case3=(lSum[i]-lSum[0])+(rSum[i]-rSum[N-1]);
        ret=max(ret,case3);
    }
}

void printResult()
{
    cout<<ret<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    input();
    solve();
    printResult();

    return 0;
}