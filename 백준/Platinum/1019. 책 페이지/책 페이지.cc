#include <iostream>

using namespace std;

int N;
int ret[10];

void input()
{
    cin>>N;
}

void solve(int weight)
{
    if(N<=0) return;

    int q=N/10;
    int r=N%10;

    for(int i=0;i<10;i++) ret[i]+=q*weight;

    for(int i=1;i<=r;i++) ret[i]+=weight;

    if(q)
    {
        int temp=q;
        while(temp)
        {
            ret[temp%10]+=(r+1)*weight;
            temp/=10;
        }
    }

    N=q-1;
    solve(weight*10);
}

void printResult()
{
    for(int i=0;i<10;i++) cout<<ret[i]<<" ";
    cout<<"\n";
}

int main()
{
    input();
    solve(1);
    printResult();

    return 0;
}